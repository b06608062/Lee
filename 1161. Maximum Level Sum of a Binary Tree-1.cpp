class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    int res = 0, mx = INT_MIN;

    queue<TreeNode *> q;
    q.push(root);

    int level = 0;
    while (!q.empty()) {
      level++;
      int sz = q.size(), cur = 0;
      while (sz--) {
        auto node = q.front();
        q.pop();
        cur += node->val;
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      if (cur > mx) {
        mx = cur;
        res = level;
      }
    }

    return res;
  }
};