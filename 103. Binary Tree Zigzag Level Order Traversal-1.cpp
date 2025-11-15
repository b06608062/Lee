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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;

    queue<TreeNode *> q;

    bool enen = false;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        level.push_back(cur->val);
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
      if (enen)
        reverse(level.begin(), level.end());
      res.push_back(level);
      enen = enen ? false : true;
    }

    return res;
  }
};