class Solution {
public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> arr1, arr2;
    helper(root1, arr1);
    helper(root2, arr2);
    return arr1 == arr2;
  }

  void helper(TreeNode *root, vector<int> &arr) {
    if (!root)
      return;
    if (!root->left && !root->right)
      arr.push_back(root->val);
    helper(root->left, arr);
    helper(root->right, arr);
  }
};