class Solution {
public:
  long long minEnd(int n, int x) {
    vector<int> X(64, 0);

    int i = 0;
    while (x) {
      X[i++] = x & 1;
      x >>= 1;
    }

    long long N = n - 1;
    for (int i = 0, j = 0; i < 64; ++i)
      if (!X[i])
        X[i] = (N >> j++) & 1;

    long long res = 0;
    for (int i = 63; i >= 0; --i) {
      res <<= 1;
      res += X[i];
    }

    return res;
  }
};