class Solution {
public:
  int binaryGap(int n) {
    int prev = -1, cur = 0, res = 0;
    while (n) {
      if (n & 1) {
        if (prev != -1)
          res = max(res, cur - prev);
        prev = cur;
      }
      n >>= 1;
      cur++;
    }

    return res;
  }
};