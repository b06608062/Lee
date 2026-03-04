class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  int islandPerimeter(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          return dfs(grid, i, j);
    return -1;
  }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
      return 1;

    if (grid[i][j] == -1) {
      return 0;
    }
    grid[i][j] = -1;
    int res = 0;
    for (int d = 0; d < 4; ++d)
      res += dfs(grid, i + dirs[d], j + dirs[d + 1]);
    return res;
  }
};