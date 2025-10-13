class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();

    int start = 0, res = 2;
    for (int i = 2; i < n; ++i) {
      if (nums[i] != nums[i - 1] + nums[i - 2])
        start = i - 1;
      res = max(res, i - start + 1);
    }

    return res;
  }
};