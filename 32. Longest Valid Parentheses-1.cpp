class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();

    stack<int> st;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      char ch = s[i];
      if (ch == '(')
        st.push(i);
      else {
        if (!st.empty() && s[st.top()] == '(') {
          st.pop();
          res = max(res, i - (st.empty() ? -1 : st.top()));
        } else
          st.push(i);
      }
    }

    return res;
  }
};

class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    st.push(-1);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty())
          st.push(i);
        else
          res = max(res, i - st.top());
      }
    }

    return res;
  }
};
