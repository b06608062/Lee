class Solution {
public:
  long long sumAndMultiply(int n) {
    int sum = 0;
    long long x = 0, prod = 1;
    while (n) {
      int mod = n % 10;
      if (mod) {
        x += mod * prod;
        prod *= 10;
        sum += mod;
      }
      n /= 10;
    }

    return x * sum;
  }
};