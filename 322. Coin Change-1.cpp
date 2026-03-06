class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    const int INF = INT_MAX / 2;
    sort(coins.begin(), coins.end());
    vector<int> f(amount + 1, INF);
    f[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (auto c : coins) {
        if (i - c < 0)
          break;
        f[i] = min(f[i], f[i - c] + 1);
      }
    }
    return f[amount] == INF ? -1 : f[amount];
  }
};