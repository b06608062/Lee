// 數位 DP
class Solution {
public:
  string s;
  int countSpecialNumbers(int n) {
    s = to_string(n);

    return dfs(0, 0, true, false);
  }

  int dfs(int i, int mask, bool isLimit, bool isNum) {
    if (i == s.size())
      return isNum ? 1 : 0;

    int res = 0;
    if (!isNum)
      res = dfs(i + 1, 0, false, false);

    int up = isLimit ? s[i] - '0' : 9;
    for (int d = isNum ? 0 : 1; d <= up; ++d)
      if ((mask & (1 << d)) == 0)
        res += dfs(i + 1, mask | (1 << d), isLimit && (d == up), true);

    return res;
  }
};