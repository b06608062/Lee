// mark
// 1927
// 經典 085
// 因為可以重新排列所以每輪可以排序後再輕鬆計算面積

class Solution {
public:
  int largestSubmatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> h(n, 0);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 1)
          h[j] += 1;
        else
          h[j] = 0;
      }
      auto temp_h = h;
      sort(temp_h.begin(), temp_h.end());
      for (int k = 0; k < n; ++k)
        res = max(res, temp_h[k] * (n - 1 - k + 1));
    }
    return res;
  }
};