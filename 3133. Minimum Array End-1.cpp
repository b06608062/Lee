class Solution {
public:
  long long minEnd(int n, int x) {
    n--;
    long long res = x;
    long long X = x;
    for (int i = 0, j = 0; n >> i; ++i) {
      while (X >> j & 1)
        j++;
      res |= (n >> i & 1LL) << j++;
    }

    return res;
  }
};