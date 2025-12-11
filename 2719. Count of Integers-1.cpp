// mark
// 2355
// 數位 DP 進階
class Solution {
public:
  const int MOD = 1e9 + 7;
  int MX, MN;
  int count(string num1, string num2, int min_sum, int max_sum) {
    MX = max_sum, MN = min_sum;

    int sum = 0;
    for (auto d : num1)
      sum += d - '0';

    long long dp1[23][401][2][2];
    long long dp2[23][401][2][2];
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    long long res =
        (dfs(dp2, num2, 0, 0, 0, 0) - dfs(dp1, num1, 0, 0, 0, 0)) % MOD;
    if (res < 0)
      res += MOD;

    return (res + (MN <= sum && sum <= MX ? 1 : 0)) % MOD;
  }

  long long dfs(long long dp[][401][2][2], string &s, int i, int sum, int free,
                int fix) {
    if (sum > MX)
      return 0;
    if (i == s.size())
      return sum >= MN ? (fix ? 1 : 0) : 0;

    long long &res = dp[i][sum][free][fix];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : (s[i] - '0');
    if (fix == 0)
      res += dfs(dp, s, i + 1, 0, 1, 0);
    res %= MOD;

    for (int d = (fix ? 0 : 1); d <= up; ++d) {
      res += dfs(dp, s, i + 1, sum + d, free || d < up, 1);
      res %= MOD;
    }

    return res;
  }
};