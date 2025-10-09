class Solution {
public:
  double myPow(double x, int n) {
    int sign = n < 0 ? -1 : 1;

    return sign == 1 ? helper(x, n) : 1.0 / helper(x, n);
  }

  double helper(double x, int n) {
    if (n == 0)
      return 1.0;

    if (n % 2 == 0)
      return helper(x * x, n / 2);
    else
      return x * helper(x * x, n / 2);
  }
};