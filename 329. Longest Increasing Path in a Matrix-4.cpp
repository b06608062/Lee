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

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dirs{0, 1, 0, -1, 0};
    auto comp = [&](auto &a, auto &b) {
      auto [ai, aj] = a;
      auto [bi, bj] = b;
      return matrix[ai][aj] > matrix[bi][bj];
    };
    using P = pair<int, int>;
    priority_queue<P, vector<P>, decltype(comp)> pq(comp);
    vector<vector<int>> f(m, vector<int>(n, 1));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        pq.push({i, j});
    int res = 0;
    while (!pq.empty()) {
      auto [i, j] = pq.top();
      pq.pop();
      int h = matrix[i][j];
      for (int d = 0; d < 4; ++d) {
        int ni = i + dirs[d], nj = j + dirs[d + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          continue;
        if (h > matrix[ni][nj])
          f[i][j] = max(f[i][j], f[ni][nj] + 1);
      }
      res = max(res, f[i][j]);
    }

    return res;
  }
};