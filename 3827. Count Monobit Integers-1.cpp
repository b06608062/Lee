class Solution {
public:
  int countMonobit(int n) {
    int res = 1;
    int cur = 0;
    while (cur < n) {
      cur <<= 1;
      cur |= 1;
      if (cur <= n)
        res++;
    }

    return res;
  }
};