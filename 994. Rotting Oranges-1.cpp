class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;

    int fresh = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          fresh++;
        else if (grid[i][j] == 2)
          q.push({i, j});

    int day = 0;
    while (!q.empty() && fresh > 0) {
      day++;
      int size = q.size();
      while (size--) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int ni = i + dirs[k], nj = j + dirs[k + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != 1)
            continue;
          grid[ni][nj] = 2;
          fresh--;
          q.push({ni, nj});
        }
      }
    }

    return fresh > 0 ? -1 : day;
  }
};