class Solution {
public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {

    return helper(root, target);
  }

  TreeNode *helper(TreeNode *root, int target) {
    if (!root)
      return nullptr;

    root->left = helper(root->left, target);
    root->right = helper(root->right, target);

    if (root->val == target && !root->left && !root->right)
      return nullptr;

    return root;
  }
};