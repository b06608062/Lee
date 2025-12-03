class Solution {
public:
  string res;
  string tree2str(TreeNode *root) {
    res = "";
    dfs(root);
    return res;
  }

  void dfs(TreeNode *root) {
    if (!root)
      return;
    res += to_string(root->val);
    if (!root->left && !root->right)
      return;
    res += '(';
    dfs(root->left);
    res += ')';
    if (root->right) {
      res += '(';
      dfs(root->right);
      res += ')';
    }
  }
};