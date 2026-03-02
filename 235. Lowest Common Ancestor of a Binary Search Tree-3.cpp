class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int p_v = p->val, q_v = q->val;
    TreeNode *cur = root;
    while (cur) {
      int r_v = cur->val;
      if (p_v < r_v && q_v < r_v)
        cur = cur->left;
      else if (p_v > r_v && q_v > r_v)
        cur = cur->right;
      else
        return cur;
    }
    return nullptr;
  }
};