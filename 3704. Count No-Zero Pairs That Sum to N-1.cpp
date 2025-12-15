// mark
// 2419
// 數位 DP 進階 + 組合兩數 + 借位處理
class Solution {
public:
  string s;
  int dp[16][2][2]; // i, borrowed, fix
  long long countNoZeroPairs(long long n) {
    s = to_string(n);
    int m = s.size();
    memset(dp, -1, sizeof(dp));

    return dfs(m - 1, 0, 0);
  }

  long long dfs(int i, int borrowed, int fix) {
    if (i < 0)
      return borrowed == 0 ? 1 : 0;

    long long res = dp[i][borrowed][fix];
    if (res != -1)
      return res;

    int d = s[i] - '0' - borrowed;
    res = 0;

    if (!fix) {
      // 兩數都不為 0
      res += dfs(i - 1, 0, 0) * two_sum_ways(d);      // 不向高位借 1
      res += dfs(i - 1, 1, 0) * two_sum_ways(d + 10); // 向高位借 1
    }

    if (i != s.size() - 1) {
      // 其中一個數位填前導 0
      // 不能是最低位，否則有一數為 0
      if (d != 0) // d 不能是 0
        // 如果 d < 0，必须向高位借 1
        // 如果 fix = -，根據對稱性 a or b 都可為前導 0，要乘以 2
        res += dfs(i - 1, d < 0, 1) * (fix ? 1 : 2);
      else if (i == 0)
        // 只有當最高位，兩數才能都填
        return 1;
    }

    return res;
  }

  int two_sum_ways(int target) {
    if (target < 2)
      return 0;
    return min(target - 1, 19 - target);
  }
};