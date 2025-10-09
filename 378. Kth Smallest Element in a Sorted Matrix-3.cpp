class Solution {
public:
  int n;
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    n = matrix.size();

    int low = matrix[0][0], hight = matrix[n - 1][n - 1];
    while (low < hight) {
      int mid = low + (hight - low) / 2;
      if (helper(matrix, mid) < k)
        low = mid + 1;
      else
        hight = mid;
    }

    return low;
  }

  int helper(vector<vector<int>> &matrix, int x) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      auto &row = matrix[i];
      int l = 0, r = n;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (row[m] <= x)
          l = m + 1;
        else
          r = m;
      }
      cnt += l;
    }

    return cnt;
  }
};