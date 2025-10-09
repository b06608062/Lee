class Solution {
public:
  int mySqrt(int x) {
    if (x == 0 || x == 1)
      return x;

    int l = 1, r = x;
    while (l < r) {
      long long m = l + (r - l) / 2;
      long long sqare = m * m;
      if (sqare <= x)
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }
};