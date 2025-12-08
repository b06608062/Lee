// Euclid’s Formula
class Solution {
public:
  int countTriples(int N) {
    int res = 0;

    for (int m = 2; m * m <= N; ++m) {
      for (int n = 1; n < m; ++n) {

        if (((m - n) & 1) == 0)
          continue; // 一奇一偶
        if (gcd(m, n) != 1)
          continue; // 互質

        int a0 = m * m - n * n;
        int b0 = 2 * m * n;
        int c0 = m * m + n * n;

        if (c0 > N)
          break;

        // 擴展所有非原始三元組
        for (int k = 1; k * c0 <= N; ++k)
          res += 2; // (a,b,c) 與 (b,a,c)
      }
    }
    return res;
  }
};
