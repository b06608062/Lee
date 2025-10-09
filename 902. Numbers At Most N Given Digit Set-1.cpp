class Solution {
public:
  string s;
  int dp[10]; // dp[pos]
  int atMostNGivenDigitSet(vector<string> &digits, int n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return dfs(digits, 0, true, false);
  }

  int dfs(vector<string> &digits, int i, bool isLimit, bool isNum) {
    if (i == s.size())
      return isNum ? 1 : 0;

    if (!isLimit && isNum) {
      int memo = dp[i];
      if (memo != -1)
        return memo;
    }

    int res = 0;
    if (!isNum)
      res += dfs(digits, i + 1, false, false);

    char up = isLimit ? s[i] : '9';
    for (auto d : digits)
      if (d[0] <= up)
        res += dfs(digits, i + 1, isLimit && (d[0] == up), true);

    return (!isLimit && isNum) ? (dp[i] = res) : res;
  }
};