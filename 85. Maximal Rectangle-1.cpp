// mark
// Monotonic Stack + 2D to 1D
// 將矩陣的每一列（Row）視為一個直方圖（Histogram）的基底
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> h(n + 1, 0);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        h[j] = matrix[i][j] == '0' ? 0 : h[j] + 1;
      }
      stack<int> st;
      for (int k = 0; k <= n; ++k) {
        while (!st.empty() && h[st.top()] > h[k]) {
          int height = h[st.top()];
          st.pop();
          int width = st.empty() ? k : k - st.top() - 1;
          res = max(res, height * width);
        }
        st.push(k);
      }
    }

    return res;
  }
};