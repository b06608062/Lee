/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int sumRootToLeaf(TreeNode *root) { return dfs(root, 0); }

  int dfs(TreeNode *root, int cur) {
    if (!root)
      return 0;
    int val = root->val;
    if (!root->left && !root->right)
      return cur << 1 | val;
    return dfs(root->left, cur << 1 | val) + dfs(root->right, cur << 1 | val);
  }
};