class Solution {
public:
  int totalMoney(int n) {
    int more = 0, res = 0;
    while (n > 0) {
      for (int i = 1; i <= min(n, 7); ++i)
        res += i + more;
      more++;
      n -= 7;
    }

    return res;
  }
};