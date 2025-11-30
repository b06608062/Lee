class Solution {
public:
  double myPow(double x, int n) {
    int e = n;
    double res = 1.0;
    while (e) {
      if (e & 1)
        res *= x;
      x *= x;
      e /= 2;
    }

    return n < 0 ? 1.0 / res : res;
  }
};