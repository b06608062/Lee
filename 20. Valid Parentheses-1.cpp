class Solution {
public:
  bool isValid(string &s) {
    stack<char> st;
    string opens = "({[";
    string closes = ")}]";

    for (char c : s)
      if (opens.find(c) != string::npos)
        st.push(c);
      else
        for (int i = 0; i < closes.size(); ++i)
          if (c == closes[i]) {
            if (!st.empty() && st.top() == opens[i])
              st.pop();
            else
              return false;
            break;
          }

    return st.empty();
  }
};
