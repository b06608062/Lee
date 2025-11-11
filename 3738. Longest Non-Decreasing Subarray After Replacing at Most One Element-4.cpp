class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();

    int pprevF0 = 0, f0 = 1, f1 = 1, res = 1;
    for (int i = 1; i < n; ++i) {
      int temp = f0;
      if (nums[i] >= nums[i - 1])
        f0++, f1++;
      else
        f0 = 1, f1 = 2;
      if (i >= 2 && nums[i] >= nums[i - 2])
        f1 = max(f1, pprevF0 + 2);
      res = max(res, max(temp + 1, f1));
      pprevF0 = temp;
    }

    return res;
  }
};