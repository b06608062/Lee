class Solution {
public:
  int k;
  int res = -1;
  int kthSmallest(TreeNode *root, int k) {
    this->k = k;
    helper(root);

    return res;
  }

  void helper(TreeNode *root) {
    if (!root)
      return;

    helper(root->left);

    if (--k == 0)
      return res = root->val;

    helper(root->right);
  }
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) { return hepler(root, k); }

  int hepler(TreeNode *root, int &k) {
    if (!root)
      return -1;
    int left = hepler(root->left, k);
    if (left >= 0)
      return left;
    if (--k == 0) {
      return root->val;
    }
    return hepler(root->right, k);
  }
};