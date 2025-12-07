class Solution {
public:
  TreeNode *replaceValueInTree(TreeNode *root) {
    if (!root)
      return root;
    root->val = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int sz = q.size();
      int nextLevelSum = 0;
      vector<TreeNode *> curLevel;

      for (int i = 0; i < sz; ++i) {
        TreeNode *node = q.front();
        q.pop();
        curLevel.push_back(node);
        if (node->left)
          nextLevelSum += node->left->val;
        if (node->right)
          nextLevelSum += node->right->val;
      }

      for (TreeNode *node : curLevel) {
        int childSum = 0;
        if (node->left)
          childSum += node->left->val;
        if (node->right)
          childSum += node->right->val;

        if (node->left) {
          node->left->val = nextLevelSum - childSum;
          q.push(node->left);
        }
        if (node->right) {
          node->right->val = nextLevelSum - childSum;
          q.push(node->right);
        }
      }
    }

    return root;
  }
};
