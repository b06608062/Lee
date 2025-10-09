class Solution {
public:
  int climbStairs(int n, vector<int> &costs) {
    vector<int> dp(n + 1, INT_MAX / 2);

    dp[0] = 0;
    dp[1] = dp[0] + 1 + costs[0];
    if (n == 1)
      return dp[1];
    dp[2] = min(dp[0] + 2 * 2, dp[1] + 1 * 1) + costs[1];
    if (n == 2)
      return dp[2];

    for (int i = 3; i <= n; ++i) {
      int best = INT_MAX / 2;
      for (int j = 1; j <= 3; ++j)
        best = min(best, dp[i - j] + j * j);
      dp[i] = best + costs[i - 1];
    }

    return dp[n];
  }
};