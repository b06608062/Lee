class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    if (!root->left && !root->right)
      return root->val == 1;

    bool left = evaluateTree(root->left);
    bool right = evaluateTree(root->right);

    return root->val == 2 ? (left || right) : (left && right);
  }
};
