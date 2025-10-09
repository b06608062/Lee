class Solution {
public:
  int cur, res;
  int subsetXORSum(vector<int> &nums) {
    cur = res = 0;
    helper(nums, 0);

    return res;
  }
  void helper(vector<int> &nums, int i) {
    if (i == nums.size()) {
      res += cur;
      return;
    }

    cur ^= nums[i];
    helper(nums, i + 1);
    cur ^= nums[i];

    helper(nums, i + 1);
  }
};