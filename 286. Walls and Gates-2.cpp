// NeetCode
class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  void islandsAndTreasure(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 0)
          for (int k = 0; k < 4; ++k)
            dfs(grid, i + dirs[k], j + dirs[k + 1], 1);
  }

  void dfs(vector<vector<int>> &grid, int i, int j, int dist) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] <= dist)
      return;

    grid[i][j] = dist;
    for (int k = 0; k < 4; ++k)
      dfs(grid, i + dirs[k], j + dirs[k + 1], dist + 1);
  }
};