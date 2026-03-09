class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
      return 0;
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    f[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (obstacleGrid[i - 1][j - 1])
          continue;
        f[i][j] = f[i - 1][j] + f[i][j - 1];
      }
    }

    return f[m][n];
  }
};