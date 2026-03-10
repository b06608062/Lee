// DFS + memo
class Solution {
public:
  vector<vector<int>> memo;
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size(), n = matrix[0].size();
    memo.assign(m, vector<int>(n, -1));
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        res = max(res, dfs(matrix, i, j));
    return res;
  }

  int dfs(vector<vector<int>> &matrix, int i, int j) {
    int &res = memo[i][j];
    if (res != -1)
      return res;
    int h = matrix[i][j];
    res = 1;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d], nj = j + dirs[d + 1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || h <= matrix[ni][nj])
        continue;
      res = max(res, dfs(matrix, ni, nj) + 1);
    }
    return res;
  }
};