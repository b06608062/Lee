class Solution {
public:
  vector<vector<string>> res;
  vector<string> subset;
  vector<vector<string>> partition(string s) {
    helper(s, "", 0);

    return res;
  }

  void helper(string &s, string curStr, int i) {
    if (i == s.size()) {
      if (curStr.size() == 0)
        res.push_back(subset);
      return;
    }

    curStr += s[i];
    if (isPalindrome(curStr)) {
      subset.push_back(curStr);
      helper(s, "", i + 1);
      subset.pop_back();
    }

    helper(s, curStr, i + 1);
  }

  bool isPalindrome(string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r)
      if (s[l++] != s[r--])
        return false;

    return true;
  }
};