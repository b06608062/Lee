class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    const int INF = INT_MAX;
    vector<int> dirs{0, 1, 0, -1, 0};
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0)
          q.push({i, j});
    int step = 0;
    while (!q.empty()) {
      step++;
      int sz = q.size();
      while (sz--) {
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int nxt_i = i + dirs[d], nxt_j = j + dirs[d + 1];
          if (nxt_i < 0 || nxt_i >= m || nxt_j < 0 || nxt_j >= n ||
              grid[nxt_i][nxt_j] != INF)
            continue;
          grid[nxt_i][nxt_j] = step;
          q.push({nxt_i, nxt_j});
        }
      }
    }
  }
};
