class Solution {
public:
  int minimumFlips(int num) {
    uint32_t n = num;
    uint32_t rev = __builtin_bitreverse32(n) >> countl_zero(n);
    return popcount(n ^ rev);
  }
};