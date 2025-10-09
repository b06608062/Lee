class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> permute(vector<int> &nums) {
    helper(nums, 0);

    return res;
  }

  void helper(vector<int> &nums, int start) {
    if (start == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = start; i < nums.size(); ++i) {
      swap(nums[start], nums[i]);
      helper(nums, start + 1);
      swap(nums[start], nums[i]);
    }
  }
};