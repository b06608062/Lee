class Solution {
public:
  double myPow(double x, int n) {
    // n < 0
    double res = pow(x, n);
    return n < 0 ? 1.0 / res : res;
  }

  double pow(double x, int n) {
    if (n == 0)
      return 1.0;
    return n % 2 ? x * pow(x * x, n / 2) : pow(x * x, n / 2);
  }
};