class Solution {
public:
  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }

  bool valid(TreeNode *root, long mm, long MM) {
    if (!root)
      return true;

    int val = root->val;
    if (val <= mm || val >= MM)
      return false;

    return valid(root->left, mm, val) && valid(root->right, val, MM);
  }
};