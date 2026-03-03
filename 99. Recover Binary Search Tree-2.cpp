class Solution {
public:
  void recoverTree(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr;
    TreeNode *prev = nullptr, *cur = root;
    auto check = [&](TreeNode *curr) {
      if (prev && prev->val > curr->val) {
        if (!first)
          first = prev;
        second = curr;
      }
      prev = curr;
    };
    while (cur) {
      if (!cur->left) {
        check(cur);
        cur = cur->right;
      } else {
        TreeNode *pre = cur->left;
        while (pre->right && pre->right != cur)
          pre = pre->right;
        if (!pre->right) {
          pre->right = cur;
          cur = cur->left;
        } else {
          pre->right = nullptr;
          check(cur);
          cur = cur->right;
        }
      }
    }
    swap(first->val, second->val);
  }
};