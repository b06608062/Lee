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
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        while (!st.empty() && h[st.top()] >= h[j]) {
          if (st.size() > 1) {
            int p1 = st.top();
            st.pop();
            int p2 = st.top();
            cnt -= (h[p1] - h[j]) * (p1 - p2);
          } else {
            cnt -= (h[st.top()] - h[j]) * (st.top() + 1);
            st.pop();
          }
        }
        cnt += h[j];
        res += cnt;
        st.push(j);
      }
    }

    return res;
  }
};