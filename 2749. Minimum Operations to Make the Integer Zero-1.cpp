// mark
// 2132
// 構造題
// 下界：最少需要 popcount(x) 個數
// 上界：最多可以拆成 x 個數

class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int k = 1; k <= 60; ++k) {
      long long x = num1 - 1ll * num2 * k;
      if (x < k) {
        return -1;
      }
      if (k >= __builtin_popcountll(x)) {
        return k;
      }
    }
    return -1;
  }
};