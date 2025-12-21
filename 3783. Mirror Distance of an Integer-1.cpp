class Solution {
public:
  int mirrorDistance(int n) { return abs(1ll * n - reverse(n)); }

  long long reverse(int n) {
    long long x = 0;
    while (n) {
      x *= 10;
      x += n % 10;
      n /= 10;
    }

    return x;
  }
};