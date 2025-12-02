class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    return helper(root).count(targetSum);
  }

  unordered_set<int> helper(TreeNode *root) {
    if (!root)
      return {};

    int x = root->val;
    if (!root->left && !root->right)
      return {x};

    unordered_set<int> uset;
    auto left = helper(root->left);
    for (auto ls : left)
      uset.insert(ls + x);

    auto right = helper(root->right);
    for (auto rs : right)
      uset.insert(rs + x);

    return uset;
  }
};