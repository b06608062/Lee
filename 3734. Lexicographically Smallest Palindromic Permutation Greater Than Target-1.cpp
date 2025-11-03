// TLE
class Solution {
public:
  string lexPalindromicPermutation(string s, string target) {
    sort(s.begin(), s.end());
    do {
      if (s > target && isPalindrome(s))
        return s;
    } while (next_permutation(s.begin(), s.end()));

    return "";
  }

  bool isPalindrome(string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i)
      if (s[i] != s[n - 1 - i])
        return false;
    return true;
  }
};