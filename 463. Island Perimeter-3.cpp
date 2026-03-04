class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int cnt_land = 0, cnt_pair = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          cnt_land++;
          if (i > 0 && grid[i - 1][j] == 1)
            cnt_pair++;
          if (j > 0 && grid[i][j - 1] == 1)
            cnt_pair++;
        }
      }
    }
    return cnt_land * 4 - cnt_pair * 2;
  }
};