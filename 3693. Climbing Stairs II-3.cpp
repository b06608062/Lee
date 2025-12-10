class Solution {
public:
  int climbStairs(int n, vector<int> &costs) {
    const int INF = INT_MAX / 2;
    vector<int> dp(n + 1, INF);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int best = INF;
      for (int j = 1; j <= 3; ++j) {
        if (i - j < 0)
          break;
        best = min(best, dp[i - j] + j * j);
      }
      dp[i] = best + costs[i - 1];
    }

    return dp[n];
  }
};
