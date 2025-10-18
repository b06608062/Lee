class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> h(n, 0);

    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j)
        h[j] = mat[i][j] ? h[j] + 1 : 0;
      stack<int> st;
      vector<int> sum(n, 0);
      for (int j = 0; j < n; ++j) {
        int hj = h[j];
        while (!st.empty() && h[st.top()] >= hj)
          st.pop();
        if (!st.empty()) {
          int prev = st.top();
          sum[j] = sum[prev] + hj * (j - prev);
        } else
          sum[j] = hj * (j + 1);
        st.push(j);
        res += sum[j];
      }
    }

    return res;
  }
};