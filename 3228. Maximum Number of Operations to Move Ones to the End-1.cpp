class Solution {
public:
  int maxOperations(string s) {
    int n = s.size();

    int ones = 0, res = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] == '1')
        ones++;
      else if (i > 0 && s[i - 1] != '0')
        res += ones;

    return res;
  }
};