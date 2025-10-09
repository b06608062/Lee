class Solution {
public:
  int mySqrt(int x) {
    long long l = 0, r = (long long)x + 1; // for 0
    while (r - l > 1) {
      long long m = l + (r - l) / 2;
      long long sqare = m * m;
      if (sqare <= x)
        l = m;
      else
        r = m;
    }

    return (int)l;
  }
};