class Solution {
public:
  vector<array<int, 2>> memo; // rest, hold
  const int inf = INT_MIN;
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    memo.assign(n, {inf, inf});

    return dfs(prices, n - 1, 0);
  }

  int dfs(vector<int> &prices, int i, int state) {
    if (i < 0)
      return state ? inf : 0;
    if (memo[i][state] != inf)
      return memo[i][state];
    if (state == 1)
      return memo[i][state] =
                 max(dfs(prices, i - 1, 1), dfs(prices, i - 2, 0) - prices[i]);
    return memo[i][state] =
               max(dfs(prices, i - 1, 0), dfs(prices, i - 1, 1) + prices[i]);
  }
};