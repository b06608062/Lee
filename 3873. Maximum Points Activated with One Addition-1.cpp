// mark
// ???
// DSU 把關係連在一起，然後找出最大的兩個 component
// 的大小，答案就是它們的大小加起來再加 1

struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  int maxActivated(vector<vector<int>> &points) {
    int n = points.size();
    DSU dsu(n);
    unordered_map<int, vector<int>> X, Y;
    for (int i = 0; i < n; ++i) {
      int x = points[i][0], y = points[i][1];
      X[x].push_back(i);
      Y[y].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      int x = points[i][0], y = points[i][1];
      dsu.unite(i, X[x][0]);
      dsu.unite(i, Y[y][0]);
    }

    vector<int> szs;
    for (int i = 0; i < n; ++i) {
      int ri = dsu.find(i);
      if (i == ri)
        szs.push_back(dsu.sz[ri]);
    }

    sort(szs.begin(), szs.end());
    if (szs.size() >= 2)
      return szs[szs.size() - 1] + szs[szs.size() - 2] + 1;
    return szs[szs.size() - 1] + 1;
  }
};