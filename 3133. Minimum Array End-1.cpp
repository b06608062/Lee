class Solution {
public:
  long long minEnd(int n, int x) {
    long long res = x;
    n--;
    for (int i = 0; i < 64 && n; ++i)
      if ((res >> i & 1) == 0) {
        res |= (n & 1ll) << i;
        n >>= 1;
      }

    return res;
  }
};