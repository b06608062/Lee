class Solution {
public:
  vector<vector<array<int, 2>>> dp;
  const int inf = INT_MIN / 2;
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (n == 0 || k == 0)
      return 0;

    dp.assign(n, vector<array<int, 2>>(k + 1, {inf, inf})); // 至多
    for (int j = 0; j <= k; ++j) {
      dp[0][j][0] = 0;
      dp[0][j][1] = (j > 0 ? -prices[0] : inf);
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        // rest
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

        // hold
        dp[i][j][1] = dp[i - 1][j][1];
        if (j > 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }

    return dp[n - 1][k][0];
  }
};

class Solution {
public:
  vector<vector<array<int, 2>>> dp;
  const int inf = INT_MIN / 2;
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (n == 0 || k == 0)
      return 0;

    dp.assign(n, vector<array<int, 2>>(k + 1, {inf, inf})); // 恰好
    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        // rest
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

        // hold
        dp[i][j][1] = dp[i - 1][j][1];
        if (j > 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }

    return dp[n - 1][k][0];
  }
};

class Solution {
public:
  vector<vector<array<int, 2>>> dp;
  const int inf = INT_MIN / 2;
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if (n == 0 || k == 0)
      return 0;

    int maxT = n / 2;
    if (k > maxT)
      return 0;

    dp.assign(n, vector<array<int, 2>>(maxT + 1, {inf, inf})); // 至少
    dp[0][0][0] = 0;
    dp[0][1][1] = -prices[0];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= maxT; ++j) {
        // rest
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

        // hold
        dp[i][j][1] = dp[i - 1][j][1];
        if (j > 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }

    int res = 0;
    for (int j = k; j <= maxT; ++j)
      res = max(res, dp[n - 1][j][0]);

    return res;
  }
};
