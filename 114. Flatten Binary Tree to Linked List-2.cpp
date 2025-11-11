class Solution {
public:
  void flatten(TreeNode *root) { dfs(root, nullptr); }

  TreeNode *dfs(TreeNode *root, TreeNode *parent) {
    if (parent) {
      parent->right = root;
      parent->left = nullptr;
    }
    if (root) {
      if (!root->left && !root->right)
        return root;
      TreeNode *temp = root->right;
      if (root->left) {
        TreeNode *leftNode = dfs(root->left, root);
        TreeNode *rightNode = dfs(temp, leftNode);
        return rightNode ? rightNode : leftNode;
      } else {
        TreeNode *rightNode = dfs(root->right, root);
        return rightNode;
      }
    }
    return nullptr;
  }
};