class Solution {
public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y,
                                       int k) {
    int m = grid.size(), n = grid[0].size();
    for (int j = y; j < y + k; ++j) {
      int top = x, bottom = x + k - 1;
      while (top < bottom)
        swap(grid[top++][j], grid[bottom--][j]);
    }

    return grid;
  }
};