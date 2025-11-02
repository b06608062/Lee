class Solution {
public:
  unordered_map<TreeNode *, int> umap;
  unordered_map<int, int> depthSum;
  TreeNode *replaceValueInTree(TreeNode *root) {
    dfs1(root, 0, 0);
    dfs2(root, 0);
    return root;
  }

  void dfs1(TreeNode *root, int siblingVal, int depth) {
    if (!root)
      return;
    umap[root] = root->val + siblingVal;
    depthSum[depth] += root->val;
    dfs1(root->left, root->right ? root->right->val : 0, depth + 1);
    dfs1(root->right, root->left ? root->left->val : 0, depth + 1);
  }

  void dfs2(TreeNode *root, int depth) {
    if (!root)
      return;
    root->val = depthSum[depth] - umap[root];
    dfs2(root->left, depth + 1);
    dfs2(root->right, depth + 1);
  }
};