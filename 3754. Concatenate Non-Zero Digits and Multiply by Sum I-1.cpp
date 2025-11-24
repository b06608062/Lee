class Solution {
public:
  long long sumAndMultiply(int n) {
    int sum = 0, shift = 0;
    long long x = 0;
    while (n) {
      int mod = n % 10;
      if (mod) {
        x += mod * (long long)pow(10, shift++);
        sum += mod;
      }
      n /= 10;
    }

    return x * sum;
  }
};