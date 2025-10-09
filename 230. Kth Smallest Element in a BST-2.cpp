class Solution {
public:
  int k;
  int res = -1;
  int kthSmallest(TreeNode *root, int k) {
    this->k = k;
    helper(root);

    return res;
  }

  void helper(TreeNode *root) {
    if (!root)
      return;

    helper(root->left);

    if (--k == 0)
      return res = root->val;

    helper(root->right);
  }
};