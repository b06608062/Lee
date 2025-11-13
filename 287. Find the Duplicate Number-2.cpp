class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int n = nums.size();

    int res = 0;
    for (int b = 0; b < 32; ++b) {
      int a = 0, e = 0;
      for (int i = 0; i < n; ++i) {
        a += (nums[i] >> b & 1);
        e += (i >> b & 1);
      }
      if (a > e)
        res |= 1 << b;
    }

    return res;
  }
};