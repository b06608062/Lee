class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    int l = 0, r = m * n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int i = mid / m;
      int j = mid % m;
      int val = matrix[i][j];
      if (val == target)
        return true;
      else if (val < target)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return false;
  }
};