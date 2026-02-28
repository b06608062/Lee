class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    stack<int> st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int h = height[i];
      while (!st.empty() && height[st.top()] <= h) {
        if (height[st.top()] < h) {
          int b_h = height[st.top()];
          st.pop();
          if (st.empty())
            break;
          int left = st.top();
          int d_h = min(height[left], h) - b_h;
          res += d_h * (i - left - 1);
        } else
          st.pop();
      }
      st.push(i);
    }
    return res;
  }
};