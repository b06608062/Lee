class Solution {
public:
  int numSquares(int n) {
    int INF = INT_MAX / 2;
    vector<int> dp(n + 1, INF);

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j * j <= i; ++j) {
        int x = i - j * j;
        dp[i] = min(dp[i], dp[x] + 1);
      }

    return dp[n];
  }
};