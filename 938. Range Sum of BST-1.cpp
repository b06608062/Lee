class Solution {
public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (!root)
      return 0;
    int x = root->val;
    if (x < low)
      return rangeSumBST(root->right, low, high);
    if (x > high)
      return rangeSumBST(root->left, low, high);
    return x + rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};