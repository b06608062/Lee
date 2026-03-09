class Solution {
public:
  vector<int> memo;
  const int INF = INT_MAX / 2;
  int numSquares(int n) {
    memo.resize(n + 1, -1);
    return dfs(n);
  }

  int dfs(int i) {
    if (i < 0)
      return INF;
    if (i == 0)
      return 0;
    int &res = memo[i];
    if (res != -1)
      return res;
    res = INF;
    for (int j = 1; j * j <= i; ++j)
      res = min(res, dfs(i - j * j) + 1);
    return res;
  }
};