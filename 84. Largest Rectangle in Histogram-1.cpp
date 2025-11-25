class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> nextSmall(n, n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        nextSmall[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }

    vector<int> prevSmall(n, -1);
    st = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        prevSmall[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
      res = max(res, heights[i] * (nextSmall[i] - prevSmall[i] - 1));

    return res;
  }
};