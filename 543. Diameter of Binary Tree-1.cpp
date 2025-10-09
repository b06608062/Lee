class Solution {
public:
  int res = 0;

  int diameterOfBinaryTree(TreeNode *root) {
    helper(root);

    return res;
  }
  int helper(TreeNode *root) {
    if (!root)
      return 0;

    int l = helper(root->left);
    int r = helper(root->right);

    res = max(res, l + r);

    return max(l, r) + 1;
  }
};