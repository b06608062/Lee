// Bellman-Ford 鬆弛
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector dp(m, vector<int>(n, 1));

    int res = 1;
    for (int k = 0; k < m * n - 1; ++k) {
      bool updated = false;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int x = matrix[i][j];
          for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || matrix[ni][nj] >= x)
              continue;
            if (dp[ni][nj] + 1 > dp[i][j]) {
              dp[i][j] = dp[ni][nj] + 1;
              updated = true;
            }
          }
          res = max(res, dp[i][j]);
        }
      if (!updated)
        break;
    }

    return res;
  }
};