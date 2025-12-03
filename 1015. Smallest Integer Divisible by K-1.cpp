// mark
// 1875
// 鴿籠原理 + MOD
class Solution {
public:
  int smallestRepunitDivByK(int k) {
    int x = 1, cnt = 1;
    while (cnt <= k) {
      if (x % k == 0)
        return cnt;
      x = x * 10 + 1;
      x %= k;
      cnt++;
    }

    return -1;
  }
};