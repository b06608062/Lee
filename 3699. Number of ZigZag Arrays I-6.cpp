// mark
// 2123
// Alternating 3D DP + Prefix Sum + 空間壓縮
// 見 1 ~ 6
class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    constexpr int MOD = 1'000'000'007;
    const int m = r - l + 1;

    vector<int> dp(m, 1), temp(m, 0);

    for (int i = 2; i <= n; ++i) {
      int pre = 0;
      for (int j = 0; j < m; ++j) {
        temp[m - 1 - j] = pre;
        pre += dp[j];
        if (pre >= MOD)
          pre -= MOD;
      }
      dp.swap(temp);
    }

    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += dp[j];
      if (res >= MOD)
        res -= MOD;
    }
    res *= 2;
    if (res >= MOD)
      res -= MOD;

    return res;
  }
};
