class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 || !root2) {
      if (!root1 && !root2)
        return nullptr;
      else
        return root1 ? root1 : root2;
    }

    return new TreeNode(root1->val + root2->val,
                        mergeTrees(root1->left, root2->left),
                        mergeTrees(root1->right, root2->right));
  }
};