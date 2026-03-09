class Solution {
public:
  vector<vector<int>> memo;
  const int INF = INT_MAX / 2;
  int m, n;
  int minPathSum(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    memo.assign(m, vector<int>(n, -1));
    return dfs(grid, m - 1, n - 1);
  }

  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || j < 0)
      return INF;
    if (i == 0 && j == 0)
      return grid[i][j];
    int &res = memo[i][j];
    if (res != -1)
      return res;
    return res = min(dfs(grid, i - 1, j), dfs(grid, i, j - 1)) + grid[i][j];
  }
};