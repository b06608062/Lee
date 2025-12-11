// mark
// 1798
// 三維 DP + 限制撤銷次數 + 注意邊界跟起點 & 初始值
class Solution {
public:
  int maximumAmount(vector<vector<int>> &coins) {
    const int INF = INT_MIN;
    int m = coins.size(), n = coins[0].size();
    vector dp(m + 1, vector<array<int, 3>>(n + 1, {INF, INF, INF}));
    int start = coins[0][0];
    dp[1][1][0] = start;
    dp[1][1][1] = dp[1][1][2] = max(0, start);

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        if (i == 1 && j == 1)
          continue;
        int c = coins[i - 1][j - 1];
        for (int k = 0; k <= 2; ++k) {
          if (dp[i - 1][j][k] != INF)
            dp[i][j][k] = dp[i - 1][j][k] + c;
          if (dp[i][j - 1][k] != INF)
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + c);
          if (c < 0 && k > 0) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
          }
        }
      }

    return dp[m][n][2];
  }
};