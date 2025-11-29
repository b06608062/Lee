// 拓樸 BFS
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> indeg(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int d = 0; d < 4; ++d) {
          int ni = i + dirs[d], nj = j + dirs[d + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
          if (matrix[ni][nj] > matrix[i][j])
            // (i, j) -> (ni, nj)
            indeg[ni][nj]++;
        }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (indeg[i][j] == 0)
          q.push({i, j});

    int res = 0;
    while (!q.empty()) {
      res++;
      int sz = q.size();
      while (sz--) {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int ni = i + dirs[d], nj = j + dirs[d + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
          if (matrix[ni][nj] > matrix[i][j])
            if (--indeg[ni][nj] == 0)
              q.push({ni, nj});
        }
      }
    }

    return res;
  }
};
