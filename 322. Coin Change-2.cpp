class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    const int INF = INT_MAX / 2;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (auto x : coins)
      for (int i = 1; i <= amount; ++i)
        if (i - x >= 0)
          dp[i] = min(dp[i], dp[i - x] + 1);

    return dp[amount] == INF ? -1 : dp[amount];
  }
};