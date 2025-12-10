// mark
// 1982
// MEMO DP + GCD 狀態壓縮 + 只搜索有可能的狀態
// O (m * n * U * log U)
class Solution {
public:
  const int MOD = 1e9 + 7;
  vector<vector<long long>> memo;
  int m, n;
  int countCoprime(vector<vector<int>> &mat) {
    m = mat.size(), n = mat[0].size();
    memo.assign(m, vector<long long>(151, -1));

    return dfs(mat, m - 1, 0);
  }

  long long dfs(vector<vector<int>> &mat, int i, int g) {
    if (i < 0)
      return g == 1 ? 1 : 0;
    auto &res = memo[i][g];
    if (res != -1)
      return res;
    res = 0;
    for (int j = 0; j < n; ++j)
      res += dfs(mat, i - 1, gcd(g, mat[i][j]));
    res %= MOD;
    return res;
  }
};