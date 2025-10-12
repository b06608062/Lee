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