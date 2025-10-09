class Solution {
public:
  int m, n;
  int islandPerimeter(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();

    int res = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1)
          res += bfs(grid, i, j);

    return res;
  }

  int bfs(vector<vector<int>> &grid, int i, int j) {
    queue<pair<int, int>> q;

    int res = 0;
    q.push({i, j});
    grid[i][j] = 2;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      // up
      if (i - 1 < 0 || grid[i - 1][j] == 0)
        res++;
      else if (grid[i - 1][j] == 1) {
        grid[i - 1][j] = 2;
        q.push({i - 1, j});
      }

      // down
      if (i + 1 >= m || grid[i + 1][j] == 0)
        res++;
      else if (grid[i + 1][j] == 1) {
        grid[i + 1][j] = 2;
        q.push({i + 1, j});
      }

      // left
      if (j - 1 < 0 || grid[i][j - 1] == 0)
        res++;
      else if (grid[i][j - 1] == 1) {
        grid[i][j - 1] = 2;
        q.push({i, j - 1});
      }

      // right
      if (j + 1 >= n || grid[i][j + 1] == 0)
        res++;
      else if (grid[i][j + 1] == 1) {
        grid[i][j + 1] = 2;
        q.push({i, j + 1});
      }
    }

    return res;
  }
};
