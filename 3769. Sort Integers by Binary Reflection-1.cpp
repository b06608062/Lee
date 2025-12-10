class Solution {
public:
  vector<int> sortByReflection(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
      long long ra = rev(a), rb = rev(b);
      if (ra != rb)
        return ra < rb;
      return a < b;
    });

    return nums;
  }

  long long rev(long long x) {
    long long res = 0;
    while (x) {
      res <<= 1;
      res |= x & 1;
      x >>= 1;
    }

    return res;
  }
};