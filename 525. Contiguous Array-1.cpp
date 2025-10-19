class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    map<int, int> mmap; // diff, idx;

    mmap[0] = -1;
    int zero = 0, one = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i])
        one++;
      else
        zero++;
      int diff = one - zero;
      if (!mmap.count(diff))
        mmap[diff] = i;
      else
        res = max(res, i - mmap[diff]);
    }

    return res;
  }
};