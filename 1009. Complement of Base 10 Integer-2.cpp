// mark
// 1235
// 先算出 n 的 bit width w，然後用 (1 << w) - 1 這個 mask 把 n 的前 w 個 bit
// 都設成 1，最後 n XOR mask 就是答案

class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0)
      return 1;
    int w = 32 - __builtin_clz(n);
    int mask = (1 << w) - 1;
    return n ^ mask;
  }
};