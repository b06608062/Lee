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
  vector<TreeNode *> arr;
  void flatten(TreeNode *root) {
    dfs(root);

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      if (i + 1 < n)
        arr[i]->right = arr[i + 1];
      else
        arr[i]->right = nullptr;
      arr[i]->left = nullptr;
    }
  }

  void dfs(TreeNode *root) {
    if (root) {
      arr.push_back(root);
      dfs(root->left);
      dfs(root->right);
    }
  }
};