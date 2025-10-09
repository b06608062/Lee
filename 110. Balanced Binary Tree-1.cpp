class Solution {
public:
  bool res = true;
  int isBalanced(TreeNode *root) {
    helper(root);

    return res;
  }

  int helper(TreeNode *root) {
    if (!root)
      return 0;

    int l = helper(root->left);
    int r = helper(root->right);

    if (abs(l - r) > 1)
      res = false;

    return max(l, r) + 1;
  }
};