class Solution {
public:
  int smallestNumber(int n) {
    int res = 0;
    while (n) {
      res <<= 1;
      res |= 1;
      n >>= 1;
    }

    return res;
  }
};