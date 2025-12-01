class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (matrix[mid][0] <= target)
        lo = mid + 1;
      else
        hi = mid;
    }

    for (int i = 0; i < lo; ++i)
      if (target <= matrix[i][n - 1])
        if (search(matrix[i], target))
          return true;

    return false;
  }

  bool search(vector<int> &row, int target) {
    int n = row.size();

    int l = 0, r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (row[m] == target)
        return true;
      else if (row[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return false;
  }
};