class Solution {
public:
  int minimumFlips(int n) {
    int bits = 0;
    int x = n;
    while (x) {
      bits++;
      x >>= 1;
    }

    int res = 0;
    for (int i = 0; i < bits / 2; ++i)
      if (((n >> i) & 1) != ((n >> (bits - 1 - i)) & 1))
        res += 2;

    return res;
  }
};