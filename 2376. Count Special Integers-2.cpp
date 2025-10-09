class Solution {
public:
  string s;
  int dp[10][1 << 10]; // dp[pos][mask]

  int countSpecialNumbers(int n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, true, false);
  }

  int dfs(int i, int mask, bool isLimit, bool isNum) {
    if (i == s.size())
      return isNum ? 1 : 0;

    // n = 321456
    // #123XXX = #213XXX
    if (!isLimit && isNum) {
      int memo = dp[i][mask];
      if (memo != -1)
        return memo;
    }

    int res = 0;
    int up = isLimit ? (s[i] - '0') : 9;

    if (!isNum)
      res += dfs(i + 1, 0, false, false);

    for (int d = isNum ? 0 : 1; d <= up; ++d)
      if ((mask & (1 << d)) == 0)
        res += dfs(i + 1, mask | (1 << d), isLimit && (d == up), true);

    return (!isLimit && isNum) ? (dp[i][mask] = res) : res;
  }
};
