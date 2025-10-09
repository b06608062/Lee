class Solution {
public:
  int res = 0;
  int goodNodes(TreeNode *root) {
    helper(root, INT_MIN);

    return res;
  }

  void helper(TreeNode *root, int curMax) {
    if (!root)
      return;

    if (root->val >= curMax)
      res++;

    curMax = max(curMax, root->val);

    helper(root->left, curMax);
    helper(root->right, curMax);
  }
};