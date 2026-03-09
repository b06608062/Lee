class Solution {
public:
  vector<int> memo, suff;
  int n;
  string stoneGameIII(vector<int> &stoneValue) {
    n = stoneValue.size();
    memo.resize(n, INT_MIN / 2);
    suff.resize(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + stoneValue[i];

    int res = dfs(stoneValue, 0);
    int diff = res - (suff[0] - res);
    return diff == 0 ? "Tie" : diff > 0 ? "Alice" : "Bob";
  }

  int dfs(vector<int> &stoneValue, int i) {
    if (i >= n)
      return 0;
    int &res = memo[i];
    if (res != INT_MIN / 2)
      return res;
    int sum = 0;
    for (int j = 0; j < 3 && i + j < n; ++j) {
      sum += stoneValue[i + j];
      res = max(res, sum + (suff[i + j + 1] - dfs(stoneValue, i + j + 1)));
    }
    return res;
  }
};