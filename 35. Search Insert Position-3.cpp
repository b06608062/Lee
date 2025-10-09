class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = -1, r = nums.size();
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      int x = nums[m];
      if (x == target)
        return m;
      else if (x < target)
        l = m;
      else
        r = m;
    }

    return r;
  }
};