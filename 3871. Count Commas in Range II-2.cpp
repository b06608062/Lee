// mark
// ???
// 貢獻法

class Solution {
public:
  long long countCommas(long long n) {
    if (n <= 999)
      return 0;
    long long low = 1000, res = 0;
    while (low <= n) {
      res += (n - low + 1);
      low *= 1000;
    }

    return res;
  }
};