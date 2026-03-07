class Solution {
public:
  vector<vector<int>> memo;
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    memo.assign(n, vector<int>(amount + 1, -1));
    return dfs(coins, n - 1, amount);
  }

  int dfs(vector<int> &coins, int i, int a) {
    if (i < 0)
      return a == 0 ? 1 : 0;
    int &res = memo[i][a];
    if (res != -1)
      return res;
    if (a < coins[i])
      return res = dfs(coins, i - 1, a);
    return res = dfs(coins, i - 1, a) + dfs(coins, i, a - coins[i]);
  }
};