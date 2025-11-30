class Solution {
public:
  long long minEnd(int n, int x) {
    vector<int> X(64, 0);

    int i = 0;
    while (x) {
      X[i++] = x & 1;
      x >>= 1;
    }

    n--;
    i = 0;
    while (n) {
      if (!X[i]) {
        X[i] = n & 1;
        n >>= 1;
      }
      i++;
    }

    long long res = 0;
    for (int i = 63; i >= 0; --i) {
      res <<= 1;
      res |= X[i];
    }

    return res;
  }
};