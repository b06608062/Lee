class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int best = 0;
      for (int j = i - 1; j > 0; --j)
        best = max(best, (i - j) * max(dp[j], j));
      dp[i] = best;
    }

    return dp[n];
  }
};