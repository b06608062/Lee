class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();
    return build(nums, 0, n - 1);
  }

  TreeNode *build(vector<int> &nums, int l, int r) {
    if (l > r)
      return nullptr;
    if (l == r)
      return new TreeNode(nums[l]);
    int m = l + (r - l) / 2;
    return new TreeNode(nums[m], build(nums, l, m - 1), build(nums, m + 1, r));
  }
};