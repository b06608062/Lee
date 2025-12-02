class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int findMaxFish(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();

    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j])
          res = max(res, dfs(grid, i, j));

    return res;
  }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
      return 0;
    int res = grid[i][j];
    grid[i][j] = 0;
    for (int d = 0; d < 4; ++d)
      res += dfs(grid, i + dirs[d], j + dirs[d + 1]);
    return res;
  }
};