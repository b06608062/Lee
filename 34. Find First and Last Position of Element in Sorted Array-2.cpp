class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();

    int l = 0, r = n;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }
    if (l == n || nums[l] != target)
      return {-1, -1};

    int first = l;
    l = 0, r = n;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] <= target)
        l = m + 1;
      else
        r = m;
    }
    int last = l - 1;
    return {first, last};
  }
};