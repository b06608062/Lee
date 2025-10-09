// NeetCode
struct Node {
  int i, j, dist;
};

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    int INF = 2147483647;
    vector<int> dirs{0, 1, 0, -1, 0};
    queue<Node> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0)
          q.push({i, j, 0});

    while (!q.empty()) {
      auto [i, j, dist] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] != INF)
          continue;
        grid[ni][nj] = dist + 1;
        q.push({ni, nj, dist + 1});
      }
    }
  }
};