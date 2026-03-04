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
  int getSize(int x) { return sz[find(x)]; }
};

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    DSU dsu(m * n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          if (i + 1 < m && grid[i + 1][j] == 1)
            dsu.unite(i * n + j, (i + 1) * n + j);
          if (j + 1 < n && grid[i][j + 1] == 1)
            dsu.unite(i * n + j, i * n + (j + 1));
        }
      }
    }
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          res = max(res, dsu.getSize(i * n + j));

    return res;
  }
};
