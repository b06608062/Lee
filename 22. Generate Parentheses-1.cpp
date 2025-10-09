class Solution {
public:
  vector<string> res;
  vector<string> generateParenthesis(int n) {
    string s;
    backtrack(s, 0, 0, n);

    return res;
  }

  void backtrack(string &s, int open, int close, int n) {
    if (s.size() == n * 2) {
      res.push_back(s);
      return;
    }

    if (open < n) {
      s.push_back('(');
      backtrack(s, open + 1, close, n);
      s.pop_back();
    }

    if (close < open) {
      s.push_back(')');
      backtrack(s, open, close + 1, n);
      s.pop_back();
    }
  }
};