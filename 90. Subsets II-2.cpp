class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    helper(nums, 0);

    return res;
  }

  void helper(vector<int> &nums, int start) {
    res.push_back(subset);

    for (int i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1])
        continue;
      subset.push_back(nums[i]);
      helper(nums, i + 1);
      subset.pop_back();
    }
  }
};