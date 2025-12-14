// mark
// 1915
// DP + 找合法切割點
class Solution {
public:
  vector<vector<long long>> dp;
  const int MOD = 1e9 + 7;
  int numberOfWays(string corridor) {
    int n = corridor.size();
    dp.assign(n, vector<long long>(3, -1));

    return dfs(corridor, n - 1, 0);
  }

  long long dfs(string &corridor, int i, int cur) {
    if (i < 0)
      return cur == 2;

    long long &res = dp[i][cur];
    if (res != -1)
      return res;

    res = 0;
    cur += corridor[i] == 'S' ? 1 : 0;
    if (cur > 2)
      return res = 0;

    if (cur == 2)
      res = dfs(corridor, i - 1, 0);
    res += dfs(corridor, i - 1, cur);

    res %= MOD;
    return res;
  }
};