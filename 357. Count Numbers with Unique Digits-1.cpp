// mark
// 數位 + 組合數學
class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
      return 1;
    // 1 : 10
    int res = 10;
    // 2 : 9 * 9
    // 3 : 9 * 9 * 8
    // 4 : 9 * 9 * 8 * 7
    for (int s = 9, i = 9, k = 2; k <= n; --i, ++k) {
      s *= i;
      res += s;
    }

    return res;
  }
};