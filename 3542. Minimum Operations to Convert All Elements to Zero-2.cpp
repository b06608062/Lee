class Solution {
public:
  int minOperations(vector<int> &nums) {
    stack<int> st;

    int res = 0;
    for (auto x : nums) {
      while (!st.empty() && x < st.top())
        st.pop();
      if (st.empty() || x > st.top()) {
        if (x > 0) {
          res++;
          st.push(x);
        }
      }
    }

    return res;
  }
};