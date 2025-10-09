class Solution {
public:
  unordered_map<TreeNode *, int> memo;
  int rob(TreeNode *root) {
    memo[nullptr] = 0;

    return helper(root);
  }

  int helper(TreeNode *root) {
    if (memo.count(root))
      return memo[root];

    int take = root->val;
    if (root->left) {
      take += helper(root->left->left);
      take += helper(root->left->right);
    }
    if (root->right) {
      take += helper(root->right->left);
      take += helper(root->right->right);
    }

    int skip = helper(root->left) + helper(root->right);

    return memo[root] = max(take, skip);
  }
};