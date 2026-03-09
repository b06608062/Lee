// mark
// 2825
// 記憶化搜索 + 狀態轉移的容斥原理
// 先全拿 dfs(z - 1, o, 0) + dfs(z - 1, o, 1)
// 扣掉不合法 當 z > limit 時，扣掉 dfs(z - limit - 1, o, 1)
// 原理：不合法的情況只有一種，就是「末尾已經連續出現了 limit 個
// 0，而我們現在又補了一個 0」。
// 最後處理 Base Case

class Solution {
public:
  int memo[1001][1001][2];
  const int MOD = 1e9 + 7;
  int l;
  int numberOfStableArrays(int zero, int one, int limit) {
    l = limit;
    memset(memo, -1, sizeof(memo));
    return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
  }

  int dfs(int z, int o, int last) {
    if (z == 0)
      return (last == 0 || o > l) ? 0 : 1;
    else if (o == 0)
      return (last == 1 || z > l) ? 0 : 1;
    int &res = memo[z][o][last];
    if (res != -1)
      return res;
    res = 0;
    if (last == 0) {
      res = (dfs(z - 1, o, 0) + dfs(z - 1, o, 1)) % MOD;
      if (z > l)
        res = (res - dfs(z - l - 1, o, 1) + MOD) % MOD;
    } else {
      res = (dfs(z, o - 1, 0) + dfs(z, o - 1, 1)) % MOD;
      if (o > l)
        res = (res - dfs(z, o - l - 1, 0) + MOD) % MOD;
    }
    return res;
  }
};