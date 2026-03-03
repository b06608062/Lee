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
  int res = INT_MIN / 2;
  int maxPathSum(TreeNode *root) {
    dfs(root);

    return res;
  }

  int dfs(TreeNode *root) {
    if (!root)
      return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    int x = root->val;
    int cur = x;
    cur += left > 0 ? left : 0;
    cur += right > 0 ? right : 0;
    res = max(res, cur);
    return max(x, max(x + left, x + right));
  }
};

class Solution {
public:
  int res = INT_MIN;
  int maxPathSum(TreeNode *root) {
    helper(root);
    return res;
  }

  int helper(TreeNode *root) {
    if (!root)
      return 0;
    int mx_l = helper(root->left);
    int mx_r = helper(root->right);
    res = max(res, root->val + mx_l + mx_r);
    return max(0, root->val + max(mx_l, mx_r));
  }
};