class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      int mid = nums[m];
      int left = nums[l];
      int right = nums[r];
      if (mid == target)
        return m;
      else if (mid >= left)                 // 上半區
        if (target >= left && target < mid) // left ~ mid
          r = m - 1;
        else
          l = m + 1;
      else                                   // 下半區
        if (target > mid && target <= right) // mid ~ right
          l = m + 1;
        else
          r = m - 1;
    }

    return -1;
  }
};