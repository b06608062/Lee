class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[n - 1])
        l = m + 1;
      else
        r = m;
    }

    return nums[l];
  }
};

class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    if (nums[0] <= nums[n - 1])
      return nums[0];
    int l = 1, r = n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[0])
        l = m + 1;
      else
        r = m;
    }

    return nums[l];
  }
};