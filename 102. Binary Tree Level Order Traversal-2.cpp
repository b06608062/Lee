class Solution {
public:
  vector<vector<int>> res;
  vector<vector<int>> levelOrder(TreeNode *root) {
    helper(root, 0);

    return res;
  }

  void helper(TreeNode *root, int level) {
    if (!root)
      return;

    if (res.size() < level + 1)
      res.push_back({});
    res[level].push_back(root->val);

    helper(root->left, level + 1);
    helper(root->right, level + 1);
  }
};