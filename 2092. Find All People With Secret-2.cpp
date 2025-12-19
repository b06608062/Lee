// mark
// 2092
// DSU with reset
class Solution {
public:
  struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
      a = find(a);
      b = find(b);
      if (a == b)
        return false;
      if (sz[a] < sz[b])
        swap(a, b);
      p[b] = a;
      sz[a] += sz[b];
      return true;
    }
    void reset(int x) {
      p[x] = x;
      sz[x] = 1;
    }
  };

  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    int m = meetings.size();
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    DSU dsu(n);
    dsu.unite(0, firstPerson);

    int i = 0, cur = 0;
    while (i < m) {
      cur = meetings[i][2];

      vector<int> people;
      while (i < m && meetings[i][2] == cur) {
        int x = meetings[i][0], y = meetings[i][1];
        dsu.unite(x, y);
        people.push_back(x);
        people.push_back(y);
        i++;
      }

      int root0 = dsu.find(0);
      for (int x : people)
        if (dsu.find(x) != root0)
          dsu.reset(x);
    }

    vector<int> res;
    int root0 = dsu.find(0);
    for (int x = 0; x < n; ++x)
      if (dsu.find(x) == root0)
        res.push_back(x);

    return res;
  }
};
