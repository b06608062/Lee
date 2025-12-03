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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> umap;
    unordered_map<int, int> indeg;
    for (auto &dec : descriptions) {
      int p = dec[0], c = dec[1];
      indeg[p] += 0;
      indeg[c]++;
      bool isLeft = dec[2] == 1;
      TreeNode *root, *child;
      if (!umap.count(p)) {
        root = new TreeNode(p);
        umap[p] = root;
      } else
        root = umap[p];
      if (!umap.count(c)) {
        child = new TreeNode(c);
        umap[c] = child;
      } else
        child = umap[c];
      isLeft ? root->left = child : root->right = child;
    }

    for (auto [x, cnt] : indeg)
      if (cnt == 0)
        return umap[x];

    return nullptr;
  }
};