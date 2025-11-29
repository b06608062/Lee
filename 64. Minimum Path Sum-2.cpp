class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));

    using T = tuple<int, int, int>; // dist, i, j
    priority_queue<T, vector<T>, greater<T>> pq;

    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});

    int dirs[2][2] = {{1, 0}, {0, 1}};

    while (!pq.empty()) {
      auto [d, i, j] = pq.top();
      pq.pop();
      if (d > dist[i][j])
        continue;
      if (i == m - 1 && j == n - 1)
        break;

      for (auto &dir : dirs) {
        int ni = i + dir[0], nj = j + dir[1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          continue;
        int nd = d + grid[ni][nj];
        if (nd < dist[ni][nj]) {
          dist[ni][nj] = nd;
          pq.push({nd, ni, nj});
        }
      }
    }

    return dist[m - 1][n - 1];
  }
};
