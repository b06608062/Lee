/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  vector<int> arr;
  TreeNode *balanceBST(TreeNode *root) {
    dfs(root);

    return build(0, arr.size() - 1);
  }
  void dfs(TreeNode *root) {
    if (!root)
      return;
    dfs(root->left);
    arr.push_back(root->val);
    dfs(root->right);
  }

  TreeNode *build(int l, int r) {
    if (l > r)
      return nullptr;
    int m = l + (r - l) / 2;
    TreeNode *newNode = new TreeNode(arr[m]);
    newNode->left = build(l, m - 1);
    newNode->right = build(m + 1, r);

    return newNode;
  }
};