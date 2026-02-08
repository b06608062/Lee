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

class Solution {
public:
  bool isBalanced(TreeNode *root) { return dfs(root) < 0 ? false : true; }

  int dfs(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int l = dfs(root->left);
    int r = dfs(root->right);
    if (l == -1 || r == -1)
      return -1;
    if (abs(l - r) > 1) {
      return -1;
    }

    return max(l, r) + 1;
  }
};