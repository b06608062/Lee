class Solution {
public:
  int totalMoney(int n) {
    int more = 0, res = 0;
    while (n > 0) {
      if (n >= 7)
        for (int i = 1; i <= 7; ++i)
          res += i + more;
      else
        for (int i = 1; i <= n; ++i)
          res += i + more;
      more++;
      n -= 7;
    }

    return res;
  }
};