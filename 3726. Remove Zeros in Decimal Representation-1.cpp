class Solution {
public:
  long long removeZeros(long long n) {
    long long base = 1, res = 0;
    while (n) {
      if (n % 10) {
        res += base * (n % 10);
        base *= 10;
      }
      n /= 10;
    }

    return res;
  }
};