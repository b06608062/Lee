class Solution {
public:
  vector<vector<array<long long, 3>>> memo; // rest, buy, sell
  const long long inf = LONG_MIN / 2;
  long long maximumProfit(vector<int> &prices, int k) {
    int n = prices.size();

    memo.assign(n, vector<array<long long, 3>>(k + 1, {inf, inf, inf}));

    return dfs(prices, n - 1, k, 0);
  }

  long long dfs(vector<int> &prices, int i, int j, int state) {
    if (j < 0)
      return inf;
    if (i < 0)
      return state ? inf : 0;
    long long &ret = memo[i][j][state];
    if (ret != inf)
      return ret;
    int x = prices[i];
    if (state == 0)
      ret = max(dfs(prices, i - 1, j, 0), max(dfs(prices, i - 1, j, 1) + x,
                                              dfs(prices, i - 1, j, 2) - x));
    else if (state == 1)
      ret = max(dfs(prices, i - 1, j, 1), dfs(prices, i - 1, j - 1, 0) - x);
    else
      ret = max(dfs(prices, i - 1, j, 2), dfs(prices, i - 1, j - 1, 0) + x);
    return ret;
  }
};