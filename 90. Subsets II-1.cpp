class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    helper(nums, 0);

    return res;
  }

  void helper(vector<int> &nums, int i) {
    if (i == nums.size()) {
      res.push_back(subset);
      return;
    }

    subset.push_back(nums[i]);
    helper(nums, i + 1);
    subset.pop_back();
    while (i + 1 < nums.size() && nums[i] == nums[i + 1])
      i++;
    helper(nums, i + 1);
  }
};