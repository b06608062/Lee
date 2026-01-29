// mark
// 2411
// 網格圖 DP + 至多 k 次 + 後綴最小值優化
// 跨層的「跳躍鬆弛」+ 同層的「路徑鬆弛」

class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    const int INF = INT_MAX;
    int m = grid.size(), n = grid[0].size();

    int mx = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mx = max(mx, grid[i][j]);
      }
    }

    vector dp(k + 1, vector(m, vector<int>(n, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int x = grid[i][j];
        if (i > 0) {
          dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j] + x);
        }
        if (j > 0) {
          dp[0][i][j] = min(dp[0][i][j], dp[0][i][j - 1] + x);
        }
      }
    }

    int res = dp[0][m - 1][n - 1];
    for (int t = 1; t <= k; ++t) {
      vector<int> min_f(mx + 1, INF);
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int x = grid[i][j];
          min_f[x] = min(min_f[x], dp[t - 1][i][j]);
        }
      }

      vector<int> suf_min(mx + 2, INF);
      for (int x = mx; x >= 0; --x) {
        suf_min[x] = min(suf_min[x + 1], min_f[x]);
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          int x = grid[i][j];
          dp[t][i][j] = min(dp[t][i][j], suf_min[x]);
          if (i > 0) {
            dp[t][i][j] = min(dp[t][i][j], dp[t][i - 1][j] + x);
          }
          if (j > 0) {
            dp[t][i][j] = min(dp[t][i][j], dp[t][i][j - 1] + x);
          }
        }
      }

      res = min(res, dp[t][m - 1][n - 1]);
    }

    return res;
  }
};