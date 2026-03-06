class Solution {
public:
  const int INF = INT_MAX / 2;
  vector<vector<int>> memo;
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    memo.assign(n, vector<int>(amount + 1, -1));
    int res = dfs(coins, n - 1, amount);
    return res == INF ? -1 : res;
  }

  int dfs(vector<int> &coins, int i, int a) {
    if (i < 0)
      return a == 0 ? 0 : INF;
    int &res = memo[i][a];
    if (res != -1)
      return res;
    if (a < coins[i])
      return res = dfs(coins, i - 1, a);
    return res = min(dfs(coins, i - 1, a), dfs(coins, i, a - coins[i]) + 1);
  }
};