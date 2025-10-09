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

      TreeNode *minNode = findMinNode(root->right);
      root->val = minNode->val;
      root->right = deleteNode(root->right, minNode->val);
    }

    return root;
  }

  TreeNode *findMinNode(TreeNode *root) {
    while (root->left)
      root = root->left;

    return root;
  }
};