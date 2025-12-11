// mark
// 1777
// 股票交易模型 + 可做空或做多 + 限制交易次數
class Solution {
public:
  vector<vector<array<long long, 3>>> dp; // rest, buy, sell
  const long long inf = LONG_MIN / 2;
  long long maximumProfit(vector<int> &prices, int k) {
    int n = prices.size();

    dp.assign(n, vector<array<long long, 3>>(k + 1, {inf, inf, inf}));
    for (int j = 0; j <= k; ++j) {
      dp[0][j][0] = 0;
      dp[0][j][1] = j > 0 ? -prices[0] : inf;
      dp[0][j][2] = j > 0 ? prices[0] : inf;
    }

    for (int i = 1; i < n; ++i) {
      int x = prices[i];
      for (int j = 0; j <= k; ++j) {
        // rest
        dp[i][j][0] =
            max(dp[i - 1][j][0], max(dp[i - 1][j][1] + x, dp[i - 1][j][2] - x));

        // buy
        dp[i][j][1] = dp[i - 1][j][1];
        if (j > 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - x);

        // sell
        dp[i][j][2] = dp[i - 1][j][2];
        if (j > 0)
          dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][0] + x);
      }
    }

    return dp[n - 1][k][0];
  }
};