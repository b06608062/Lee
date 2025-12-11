class Solution {
public:
  string s;
  long long dp[15][2][2];
  long long countDistinct(long long n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 0);
  }

  long long dfs(int i, int free, int fix) {
    if (i == s.size())
      return fix ? 1 : 0;

    long long &res = dp[i][free][fix];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');

    if (fix == 0)
      res += dfs(i + 1, 1, 0);

    for (int d = 1; d <= up; ++d)
      res += dfs(i + 1, free || d < up, 1);

    return res;
  }
};