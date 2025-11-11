class Solution {
public:
  vector<vector<array<int, 2>>> memo;
  const int inf = INT_MIN / 2;
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    memo.assign(n, vector<array<int, 2>>(k + 1, {inf, inf})); // 至多

    return dfs(prices, n - 1, k, 0);
  }

  int dfs(vector<int> &prices, int i, int j, int state) {
    if (j < 0)
      return inf;
    if (i < 0)
      return state ? inf : 0;
    int &ret = memo[i][j][state];
    if (ret != inf)
      return ret;
    if (state == 1) // hold
      ret = max(dfs(prices, i - 1, j, 1),
                dfs(prices, i - 1, j - 1, 0) - prices[i]);
    else // rest
      ret = max(dfs(prices, i - 1, j, 0), dfs(prices, i - 1, j, 1) + prices[i]);
    return ret;
  }
};