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

class Solution {
public:
  int integerBreak(int n) {
    vector<int> f(n + 1, 0);
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
      for (int j = 1; j <= i / 2; ++j)
        f[i] = max(f[i], max(f[i - j], i - j) * max(f[j], j));
    return f[n];
  }
};