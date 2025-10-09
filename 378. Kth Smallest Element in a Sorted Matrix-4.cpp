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
    // O(n) : 由左下角往右上角走
    int r = n - 1, c = 0, cnt = 0;
    while (r >= 0 && c < n) {
      if (matrix[r][c] <= x) {
        cnt += r + 1;
        c++;
      } else
        r--;
    }

    return cnt;
  }
};