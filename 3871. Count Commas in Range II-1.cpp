class Solution {
public:
  long long countCommas(long long n) {
    if (n <= 999)
      return 0;
    long long cur = 1000, res = 0;
    int i = 0;
    while (true) {
      long long prev = cur;
      cur *= 1000;
      res += (min(n, cur - 1) - prev + 1) * ++i;
      if (cur >= n) {
        res += cur == n ? i + 1 : 0;
        break;
      }
    }
    return res;
  }
};