class Solution {
public:
  vector<vector<string>> res;
  vector<string> subset;
  vector<vector<string>> partition(string s) {
    helper(s, 0);

    return res;
  }

  void helper(string &s, int start) {
    int n = s.size();
    if (start == n) {
      res.push_back(subset);
      return;
    }

    for (int i = start; i < n; ++i) {
      string subStr = s.substr(start, i - start + 1);
      if (isPalindrome(subStr)) {
        subset.push_back(subStr);
        helper(s, i + 1);
        subset.pop_back();
      }
    }
  }

  bool isPalindrome(string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r)
      if (s[l++] != s[r--])
        return false;

    return true;
  }
};