// lazy dp
class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 1e6));
    vector<int> dirs{0, 1, 0, -1, 0};

    dp[0][0] = 0;
    for (int l = 0; l < m * n - 1; ++l) {
      bool updated = true;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
          int toH = heights[i][j];
          for (int k = 0; k < 4; ++k) {
            int ni = i + dirs[k], nj = j + dirs[k + 1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
              continue;
            int cost = max(dp[ni][nj], abs(heights[ni][nj] - toH));
            if (cost < dp[i][j]) {
              dp[i][j] = cost;
              updated = false;
            }
          }
        }
      if (updated)
        break;
    }

    return dp[m - 1][n - 1];
  }
};