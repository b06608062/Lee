// mark
// ???
// 數位 DP

class Solution {
  // dp[i][free][fix][is_inc][is_dec][pre][sum]
  long long dp[16][2][2][2][2][11][140];
  string s;

  bool checkGoodSum(int n) {
    if (n < 10)
      return true;
    string t = to_string(n);
    bool inc = true, dec = true;
    for (int i = 1; i < t.size(); ++i) {
      if (t[i] <= t[i - 1])
        inc = false;
      if (t[i] >= t[i - 1])
        dec = false;
    }
    return inc || dec;
  }

  long long dfs(int i, bool free, bool fix, bool is_inc, bool is_dec, int pre,
                int sum) {
    if (i == s.size()) {
      return fix && (is_inc || is_dec || checkGoodSum(sum)) ? 1 : 0;
    }
    long long &res = dp[i][free][fix][is_inc][is_dec][pre][sum];
    if (res != -1)
      return res;

    res = 0;
    int up = free ? 9 : s[i] - '0';
    for (int d = 0; d <= up; ++d) {
      bool next_free = free || (d < up);
      if (!fix) {
        if (d == 0) {
          // 繼續保持前導零狀態
          res += dfs(i + 1, next_free, false, true, true, 10, 0);
        } else {
          // 填入第一個非零數字：此時 is_inc/is_dec 必為 true，且不需跟 pre 比較
          res += dfs(i + 1, next_free, true, true, true, d, d);
        }
      } else {
        // 已經開始有數字了，進行單調性判斷
        bool next_inc = is_inc && (d > pre);
        bool next_dec = is_dec && (d < pre);
        res += dfs(i + 1, next_free, true, next_inc, next_dec, d, sum + d);
      }
    }
    return res;
  }

  long long solve(long long n) {
    if (n < 0)
      return 0;
    s = to_string(n);
    memset(dp, -1, sizeof(dp));
    return dfs(0, false, false, true, true, 10, 0);
  }

public:
  long long countFancy(long long l, long long r) {
    return solve(r) - solve(l - 1);
  }
};