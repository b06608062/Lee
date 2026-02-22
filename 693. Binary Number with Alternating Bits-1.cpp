class Solution {
public:
  bool hasAlternatingBits(int n) {
    int w = bit_width((uint32_t)n);
    for (int i = 0; i < w - 1; ++i)
      if ((n >> i & 1) == (n >> (i + 1) & 1))
        return false;
    return true;
  }
};