class Solution {
public:
  bool hasSameDigits(string s) {
    while (s.size() > 2) {
      for (int i = 0; i < s.size() - 1; ++i)
        s[i] = (s[i] + s[i + 1]) % 10 + '0';
      s.pop_back();
    }

    return s[0] == s[1];
  }
};