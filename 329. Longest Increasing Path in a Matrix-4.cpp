// 排序 DP
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> dp(m, vector<int>(n, 1));

    vector<tuple<int, int, int>> nodes;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        nodes.push_back({matrix[i][j], i, j});

    sort(nodes.begin(), nodes.end());

    int res = 1;
    for (auto &[val, i, j] : nodes) {
      for (int d = 0; d < 4; ++d) {
        int ni = i + dirs[d], nj = j + dirs[d + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          continue;
        if (matrix[ni][nj] < val)
          dp[i][j] = max(dp[i][j], dp[ni][nj] + 1);
      }
      res = max(res, dp[i][j]);
    }

    return res;
  }
};
