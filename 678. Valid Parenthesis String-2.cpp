class Solution {
public:
  bool checkValidString(string s) {
    int n = s.size();

    int left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
      left += s[i] != ')' ? 1 : -1;
      right += s[n - i - 1] != '(' ? 1 : -1;
      if (left < 0 || right < 0)
        return false;
    }

    return true;
  }
};