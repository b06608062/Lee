class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    if (nums[0] <= nums[n - 1])
      return nums[0];

    int left = nums[0];
    int l = 0, r = n - 1;
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      if (nums[m] >= left) {
        l = m;
      } else {
        r = m;
      }
    }

    return nums[r];
  }
};