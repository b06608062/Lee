struct Element {
  string s;
  int open, close;
};

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    stack<Element> st;

    vector<string> res;
    st.push({"", 0, 0});
    while (!st.empty()) {
      auto &cur = st.top();
      st.pop();

      if (cur.s.size() == n * 2) {
        res.push_back(cur.s);
        continue;
      }

      if (cur.open < n)
        st.push({cur.s + "(", cur.open + 1, cur.close});

      if (cur.close < cur.open)
        st.push({cur.s + ")", cur.open, cur.close + 1});
    }

    return res;
  }
};
