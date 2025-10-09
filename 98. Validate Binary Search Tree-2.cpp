class Solution {
public:
  vector<int> arr;
  bool isValidBST(TreeNode *root) {
    inorder(root);

    set<int> sset(arr.begin(), arr.end());
    vector<int> sortVec(sset.begin(), sset.end());

    return arr == sortVec;
  }
  void inorder(TreeNode *root) {
    if (!root)
      return;

    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
  }
};