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

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int f0 = 0, f1 = 0, f2 = INT_MIN; // prev rest, rest, hold
    for (auto x : prices) {
      int new_f2 = max(f2, f0 - x);
      f0 = f1;
      f1 = max(f1, f2 + x);
      f2 = new_f2;
    }

    return f1;
  }
};