// DFS + memo（lazy DP）
class Solution {
public:
  vector<vector<int>> memo;
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size(), n = matrix[0].size();
    memo.assign(m, vector<int>(n, 0));

    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        res = max(res, dfs(matrix, i, j, LLONG_MAX));

    return res;
  }

  int dfs(vector<vector<int>> &matrix, int i, int j, long long from) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] >= from)
      return 0;
    if (memo[i][j] != 0)
      return memo[i][j];
    int x = matrix[i][j];
    int best = 1;
    for (int d = 0; d < 4; ++d)
      best = max(best, dfs(matrix, i + dirs[d], j + dirs[d + 1], x) + 1);
    return memo[i][j] = best;
  }
};