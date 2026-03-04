class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int numIslands(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          ++res;
          q.push({i, j});
          grid[i][j] = '0';
          while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
              int nxt_i = i + dirs[d], nxt_j = j + dirs[d + 1];
              if (nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n ||
                  grid[nxt_i][nxt_j] == '0')
                continue;
              grid[nxt_i][nxt_j] = '0';
              q.push({nxt_i, nxt_j});
            }
          }
        }
      }
    }

    return res;
  }
};
