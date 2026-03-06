class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    const int INF = INT_MAX / 2;
    vector<int> f(amount + 1, INF);
    f[0] = 0;
    for (auto c : coins)
      for (int i = c; i <= amount; ++i)
        f[i] = min(f[i], f[i - c] + 1);
    return f[amount] == INF ? -1 : f[amount];
  }
};