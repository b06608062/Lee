// mark
// 2200
// 分塊轉移 DP
// 以「區塊」為單位進行決策

class Solution {
public:
  const int MOD = 1e9 + 7;
  int l;
  int memo[201][201][2];
  int numberOfStableArrays(int zero, int one, int limit) {
    l = limit;
    memset(memo, -1, sizeof(memo));
    long long res = (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    return res;
  }

  long long dfs(int z, int o, int last) {
    if (z == 0 && o == 0)
      return 1;
    int &res = memo[z][o][last];
    if (res != -1)
      return res;
    res = 0;
    if (last == 0) {
      for (int k = 1; k <= min(o, l); ++k)
        res = (res + dfs(z, o - k, 1)) % MOD;
    } else {
      for (int k = 1; k <= min(z, l); ++k)
        res = (res + dfs(z - k, o, 0)) % MOD;
    }
    return res;
  }
};