class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return nullptr;

    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else {
      // equal to key
      if (!root->left)
        return root->right;
      if (!root->right)
        return root->left;

      TreeNode *newRoot = root->right;
      TreeNode *parent = root;
      while (newRoot->left) {
        parent = newRoot;
        newRoot = newRoot->left;
      }

      if (parent != root) {
        parent->left = newRoot->right;
        newRoot->right = root->right;
      }

      newRoot->left = root->left;
      return newRoot;
    }

    return root;
  }
};