class Solution {
public:
  vector<vector<int>> memo;
  vector<int> suff;
  const int INF = INT_MAX / 2;
  int n;
  int stoneGameII(vector<int> &piles) {
    n = piles.size();
    const int INF = INT_MAX / 2;
    memo.assign(n, vector<int>(n + 1, -INF));
    suff.resize(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + piles[i];

    // A - B = f[0][1]
    // A + B = suff[0]
    // A = (f[0][1] + suff[0]) / 2
    return (dfs(piles, 0, 1) + suff[0]) / 2;
  }

  int dfs(vector<int> &piles, int i, int M) {
    if (i >= n)
      return 0;
    int &res = memo[i][M];
    if (res != -INF)
      return res;
    if (i + 2 * M - 1 >= n - 1)
      return res = suff[i];
    int sum = 0;
    for (int X = 1; X <= 2 * M; ++X) {
      sum += piles[i + X - 1];
      res = max(res, sum - dfs(piles, i + X, max(M, X)));
    }
    return res;
  }
};