// mark
// ???
// 試填法 + 組合數
// 從高位到低位決定每一位是 0 還是 1，類似二分搜尋
class Solution {
public:
  long long nthSmallest(long long n, int k) {
    constexpr int MX = 50;
    long long comb[MX][MX + 1];
    for (int i = 0; i < MX; ++i) {
      comb[i][0] = 1;
      for (int j = 1; j <= i; ++j) {
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      }
    }

    long long res = 0;
    for (int i = MX - 1; i >= 0; --i) {
      auto c = comb[i][k]; // 第 i 位填 0 的方案數
      if (n > c) {
        n -= c;
        res |= 1ll << i;
        k--;
      }
    }

    return res;
  }
};