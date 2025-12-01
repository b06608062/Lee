class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
      int x = matrix[row][col];
      if (x == target)
        return true;
      else if (x < target)
        row++;
      else
        col--;
    }

    return false;
  }
};