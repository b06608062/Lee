class Solution {
public:
  vector<int> res;
  vector<int> rightSideView(TreeNode *root) {
    helper(root, 0);

    return res;
  }

  void helper(TreeNode *root, int level) {
    if (!root)
      return;

    if (level == res.size())
      res.push_back(root->val);
    helper(root->right, level + 1);
    helper(root->left, level + 1);
  }
};