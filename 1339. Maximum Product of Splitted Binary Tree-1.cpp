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
  unordered_map<TreeNode *, long long> dp;
  long long total, res;
  int maxProduct(TreeNode *root) {
    const int MOD = 1e9 + 7;
    dfs(root);
    total = dp[root];
    res = 0;
    for (auto &[_, sum] : dp)
      res = max(res, sum * (total - sum));

    return res % MOD;
  }
  void dfs(TreeNode *root) {
    if (!root)
      return;
    dp[root] = root->val;
    if (root->left) {
      dfs(root->left);
      dp[root] += dp[root->left];
    }
    if (root->right) {
      dfs(root->right);
      dp[root] += dp[root->right];
    }
  }
};