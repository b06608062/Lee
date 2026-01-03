// mark
// 1845
// Coloring DP
// (i - 1, j) 與 (i, j - 1) 不是獨立事件，無法用乘法原理
class Solution {
public:
  int numOfWays(int n) {
    const int MOD = 1e9 + 7;
    long long a = 6; // ABA type
    long long b = 6; // ABC type

    for (int i = 2; i <= n; ++i) {
      // ABA -> BAB, CAC, CBC
      // ABC -> BAB, BCB
      long long na = (3 * a + 2 * b) % MOD;

      // ABA -> BAC, CAB
      // ABC -> CAB, BCA
      long long nb = (2 * a + 2 * b) % MOD;
      a = na;
      b = nb;
    }

    return (a + b) % MOD;
  }
};
