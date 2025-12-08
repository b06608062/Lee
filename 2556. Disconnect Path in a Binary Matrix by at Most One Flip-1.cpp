// mark
// 2369
// DFS + Path Cutting（兩次 DFS 摧毀路徑法，先走最下方路徑）
class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    auto dfs = [&](auto &&self, int i, int j) -> bool {
      if (i == m - 1 && j == n - 1)
        return true;
      grid[i][j] = 0;
      return (i + 1 < m && grid[i + 1][j] && self(self, i + 1, j)) ||
             (j + 1 < n && grid[i][j + 1] && self(self, i, j + 1));
    };

    return !dfs(dfs, 0, 0) || !dfs(dfs, 0, 0);
  }
};

class Solution {
public:
  int m, n;
  bool isPossibleToCutPath(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    if (!dfs(grid, 0, 0))
      return true;
    grid[0][0] = 1;
    return !dfs(grid, 0, 0);
  }

  bool dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
      return false;
    if (i == m - 1 && j == n - 1)
      return true;
    grid[i][j] = 0;
    return dfs(grid, i + 1, j) || dfs(grid, i, j + 1);
  }
};