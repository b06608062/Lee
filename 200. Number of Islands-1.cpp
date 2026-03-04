class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  int numIslands(vector<vector<char>> &grid) {
    m = grid.size(), n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '1') {
          res++;
          dfs(grid, i, j);
        }
    return res;
  }

  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
      return;
    grid[i][j] = '0';
    for (int d = 0; d < 4; ++d)
      dfs(grid, i + dirs[d], j + dirs[d + 1]);
  }
};
