class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (!root)
      return res;

    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        if (i == size - 1)
          res.push_back(cur->val);
        if (cur->left)
          q.push(cur->left);
        if (cur->right)
          q.push(cur->right);
      }
    }

    return res;
  }
};