class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    unordered_set<int> uset({2, 3, 5, 7, 11, 13, 17, 19});
    int res = 0;
    for (int i = left; i <= right; ++i)
      if (uset.find(count_bit(i)) != uset.end())
        res++;
    return res;
  }

  int count_bit(int n) {
    int bit = 0;
    while (n > 0) {
      bit += n & 1;
      n >>= 1;
    }
    return bit;
  }
};