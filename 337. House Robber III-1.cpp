class Solution {
public:
  int rob(TreeNode *root) {
    pair<int, int> res = helper(root);

    return max(res.first, res.second);
  }
  pair<int, int> helper(TreeNode *root) {
    if (!root)
      return {0, 0};

    pair<int, int> l = helper(root->left);
    pair<int, int> r = helper(root->right);

    int t = l.second + r.second + root->val;
    int nt = max(l.first, l.second) + max(r.first, r.second);

    return {t, nt};
  }
};