class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();

    int l = -1, r = n - 1;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[m + 1])
        l = m;
      else
        r = m;
    }

    return r;
  }
};