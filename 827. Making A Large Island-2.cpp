// mark
// 1934
// Grid Connected Components + Flip Optimization + DSU
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
    p[b] = a, sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int largestIsland(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();

    DSU dsu(m * n);

    int maxArea = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          int root = i * n + j;
          dfs(grid, dsu, i, j, root);
          maxArea = max(maxArea, dsu.sz[root]);
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          unordered_set<int> uset;
          for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 0)
              continue;
            uset.insert(dsu.find(ni * n + nj));
          }
          int area = 1;
          for (auto v : uset)
            area += dsu.sz[v];
          maxArea = max(maxArea, area);
        }
      }

    return maxArea;
  }

  void dfs(vector<vector<int>> &grid, DSU &dsu, int i, int j, int root) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
      return;
    grid[i][j] = -1;
    int u = i * n + j;
    dsu.unite(root, u);
    for (int d = 0; d < 4; ++d)
      dfs(grid, dsu, i + dirs[d], j + dirs[d + 1], root);
  }
};