// mark
// 數位 DP 進階
// 2120
class Solution {
public:
  string s;
  int dp[11][2][2][1 << 10];
  int countSpecialNumbers(int n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 0, 0);
  }

  int dfs(int i, int free, int fix, int mask) {
    if (i == s.size())
      return fix ? 1 : 0;

    int &res = dp[i][free][fix][mask];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');

    if (fix == 0)
      res += dfs(i + 1, 1, 0, mask);

    for (int d = (fix == 0 ? 1 : 0); d <= up; ++d) {
      if (mask & (1 << d))
        continue;
      res += dfs(i + 1, free || (d < up), 1, mask | (1 << d));
    }

    return res;
  }
};