class Solution {
public:
  bool checkValidString(string s) {
    int n = s.size();

    int low = 0, high = 0;
    for (int i = 0; i < n; ++i) {
      low += s[i] == '(' ? 1 : -1;
      high += s[i] != ')' ? 1 : -1;
      if (high < 0)
        break;
      low = max(low, 0);
    }

    return low == 0;
  }
};