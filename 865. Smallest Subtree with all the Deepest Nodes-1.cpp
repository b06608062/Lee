// mark
// 1534
// BT + LCA
class Solution {
public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) { return dfs(root).second; }
  pair<int, TreeNode *> dfs(TreeNode *root) {
    if (!root)
      return {0, nullptr};
    auto [ld, lch] = dfs(root->left);
    auto [rd, rch] = dfs(root->right);
    if (ld == rd)
      return {ld + 1, root};
    if (ld > rd)
      return {ld + 1, lch};
    return {rd + 1, rch};
  }
};