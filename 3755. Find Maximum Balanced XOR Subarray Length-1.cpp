class Solution {
public:
  int maxBalancedSubarray(vector<int> &nums) {
    int n = nums.size();

    using P = pair<int, int>; // pxor, diff
    map<P, int> mmap;

    mmap[{0, 0}] = -1;
    int pxor = 0, diff = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      diff += x % 2 ? -1 : 1;
      pxor ^= x;
      P p = {pxor, diff};
      if (!mmap.count(p))
        mmap[p] = i;
      else
        res = max(res, i - mmap[p]);
    }

    return res;
  }
};