class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n - 2;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[m + 1])
        l = m + 1;
      else
        r = m - 1;
    }

    return l;
  }
};