class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      int x = nums[m];
      if (x == target)
        return m;
      else if (x < target)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};