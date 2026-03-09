class Solution {
public:
  vector<int> memo;
  int n;
  string stoneGameIII(vector<int> &stoneValue) {
    n = stoneValue.size();
    memo.resize(n, INT_MIN / 2);
    int res = dfs(stoneValue, 0);
    return res == 0 ? "Tie" : res > 0 ? "Alice" : "Bob";
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
      res = max(res, sum - dfs(stoneValue, i + j + 1));
    }
    return res;
  }
};