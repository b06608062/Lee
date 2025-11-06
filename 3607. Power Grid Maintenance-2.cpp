// Successor Union-Find

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
};

class Solution {
public:
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    int n = c;
    DSU dsu(n + 1);

    for (auto &e : connections)
      dsu.unite(e[0], e[1]);

    vector<int> next(n + 1, 0), compMin(n + 1, 0), last(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int rX = dsu.find(i);
      if (compMin[rX] == 0)
        compMin[rX] = i;
      else
        next[last[rX]] = i;
      last[rX] = i;
    }

    vector<bool> online(n + 1, true);

    vector<int> res;
    for (auto &q : queries) {
      int x = q[1];
      int rX = dsu.find(x);
      if (q[0] == 1) {
        if (online[x])
          res.push_back(x);
        else
          res.push_back(compMin[rX] ? compMin[rX] : -1);
      } else {
        if (online[x]) {
          online[x] = false;
          // lazy maintenance
          if (x == compMin[rX]) {
            int y = next[x];
            while (y && !online[y])
              y = next[y];
            compMin[rX] = y;
          }
        }
      }
    }

    return res;
  }
};