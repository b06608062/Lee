class Solution {
public:
  int countCommas(int n) {
    int res = 0;
    for (int i = 1000; i <= n; ++i) {
      int x = i;
      while (x >= 1000) {
        res++;
        x /= 1000;
      }
    }
    return res;
  }
};