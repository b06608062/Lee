class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  vector<vector<int>> subsets(vector<int> &nums) {
    helper(nums, 0);

    return res;
  }

  void helper(vector<int> &nums, int start) {
    res.push_back(subset);

    for (int i = start; i < nums.size(); ++i) {
      subset.push_back(nums[i]);
      helper(nums, i + 1);
      subset.pop_back();
    }
  }
};