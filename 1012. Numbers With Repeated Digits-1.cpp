// mark
// 2230
// 數位 DP 進階
class Solution {
public:
  string s;
  int dp[10][2][2][1 << 10][2];
  int numDupDigitsAtMostN(int n) {
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 0, 0, 0);
  }

  int dfs(int i, int free, int fix, int mask, int repeat) {
    if (i == s.size())
      return fix && repeat ? 1 : 0;

    int &res = dp[i][free][fix][mask][repeat];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');

    if (fix == 0)
      res += dfs(i + 1, 1, 0, mask, 0);

    for (int d = (fix == 0 ? 1 : 0); d <= up; ++d)
      res += dfs(i + 1, free || (d < up), 1, mask | (1 << d),
                 repeat || mask >> d & 1);

    return res;
  }
};