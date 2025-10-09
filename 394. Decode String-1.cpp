class Solution {
public:
  string decodeString(string s) {
    stack<int> st1;
    stack<string> st2;

    st2.push("");
    int i = 0;
    while (i < s.size()) {
      char ch = s[i];
      if (isDigit(ch)) {
        int j = s.find('[', i);
        st1.push(stoi(s.substr(i, j - i)));
        st2.push("");
        i = j + 1;
      } else if (ch == ']') {
        string decoded = st2.top();
        st2.pop();
        int repeat = st1.top();
        st1.pop();
        for (int k = 0; k < repeat; ++k)
          st2.top() += decoded;
        i++;
      } else {
        st2.top().push_back(ch);
        i++;
      }
    }

    return st2.top();
  }

  bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
};
