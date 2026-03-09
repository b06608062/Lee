class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
      return 0;
    vector<int> f(n, 0);
    f[0] = 1;
    for (int i = 0; i < m; ++i) {
      if (obstacleGrid[i][0])
        f[0] = 0;
      for (int j = 1; j < n; ++j)
        if (!obstacleGrid[i][j])
          f[j] += f[j - 1];
        else
          f[j] = 0;
    }
    return f[n - 1];
  }
};

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
      return 0;
    vector<int> f(n, 0);
    f[0] = 1;
    for (int i = 0; i < m; ++i) {
      vector<int> nxt_f(n, 0);
      if (!obstacleGrid[i][0])
        nxt_f[0] = f[0];
      for (int j = 1; j < n; ++j)
        if (!obstacleGrid[i][j])
          nxt_f[j] = nxt_f[j - 1] + f[j];
      f.swap(nxt_f);
    }
    return f[n - 1];
  }
};