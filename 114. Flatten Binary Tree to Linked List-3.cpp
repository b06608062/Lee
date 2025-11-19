class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *cur = root;
    while (cur) {
      if (cur->left) {
        TreeNode *pre = cur->left;
        while (pre->right)
          pre = pre->right;
        pre->right = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;
      }
      cur = cur->right;
    }
  }
};

class Solution {
public:
  void flatten(TreeNode *root) {
    TreeNode *cur = root;
    while (cur) {
      if (!cur->left) {
        cur = cur->right;
        continue;
      }
      TreeNode *pre = cur->left;
      while (pre->right)
        pre = pre->right;
      pre->right = cur->right;
      cur->right = cur->left;
      cur->left = nullptr;
    }
  }
};