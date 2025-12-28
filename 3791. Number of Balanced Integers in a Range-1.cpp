// mark
// ???
// 數位 DP 老招
class Solution {
public:
  long long countBalanced(long long low, long long high) {
    string str1 = to_string(low - 1);
    string str2 = to_string(high);

    long long dp1[16][2][2][136][136];
    long long dp2[16][2][2][136][136];
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    return dfs(dp2, str2, 0, 0, 0, 0, 0) - dfs(dp1, str1, 0, 0, 0, 0, 0);
  }

  long long dfs(long long dp[][2][2][136][136], string &s, int i, int free,
                int fix, int odd, int even) {
    if (i == s.size())
      return fix && odd == even;

    long long &res = dp[i][free][fix][odd][even];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');
    if (fix == 0)
      res += dfs(dp, s, i + 1, 1, 0, 0, 0);

    for (int d = (fix ? 0 : 1); d <= up; ++d)
      if (i % 2 == 0)
        res += dfs(dp, s, i + 1, free || d < up, 1, odd, even + d);
      else
        res += dfs(dp, s, i + 1, free || d < up, 1, odd + d, even);

    return res;
  }
};