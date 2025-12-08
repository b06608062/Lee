// mark
// 1500
// 快速質因數分解模擬
class Solution {
public:
  int smallestValue(int n) {
    while (true) {
      int cur = n, sum = 0;
      for (int i = 2; i * i <= cur; ++i)
        while (cur % i == 0) {
          cur /= i;
          sum += i;
        }
      if (cur > 1)
        sum += cur;

      if (sum == n)
        break;
      n = sum;
    }

    return n;
  }
};