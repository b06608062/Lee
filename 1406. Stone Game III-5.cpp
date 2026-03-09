class Solution {
public:
  vector<array<int, 2>> memo;
  const int INF = 1e9;
  int n;
  string stoneGameIII(vector<int> &stoneValue) {
    n = stoneValue.size();
    memo.assign(n, {-INF, INF});
    int res = dfs(stoneValue, 0, 0);
    return res == 0 ? "Tie" : res > 0 ? "Alice" : "Bob";
  }

  int dfs(vector<int> &stoneValue, int i, int j) {
    if (i >= n)
      return 0;
    int &res = memo[i][j];
    if (abs(res) != INF)
      return res;
    int sum = 0;
    for (int k = 0; k < 3 && i + k < n; ++k) {
      sum += stoneValue[i + k];
      if (j == 0)
        res = max(res, sum + dfs(stoneValue, i + k + 1, !j));
      else
        res = min(res, -sum + dfs(stoneValue, i + k + 1, !j));
    }
    return res;
  }
};
