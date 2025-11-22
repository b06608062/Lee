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
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    if (m * n == 1)
      return 0;

    vector<vector<int>> edges; // cost, u, v
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int u = i * n + j;
        int uH = heights[i][j];
        if (i + 1 < m) {
          int v = (i + 1) * n + j;
          edges.push_back({abs(uH - heights[i + 1][j]), u, v});
        }
        if (j + 1 < n) {
          int v = i * n + j + 1;
          edges.push_back({abs(uH - heights[i][j + 1]), u, v});
        }
      }

    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    DSU dsu(m * n);

    for (auto &e : edges) {
      dsu.unite(e[1], e[2]);
      if (dsu.find(0) == dsu.find(m * n - 1))
        return e[0];
    }

    return -1;
  }
};