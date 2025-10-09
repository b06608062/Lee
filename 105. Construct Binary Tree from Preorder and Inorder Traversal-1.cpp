class Solution {
public:
  unordered_map<int, int> umap;
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; ++i)
      umap[inorder[i]] = i;

    return helper(preorder, 0, 0, n - 1);
  }

  TreeNode *helper(vector<int> &preorder, int D, int L, int R) {
    if (L > R)
      return nullptr;

    int val = preorder[D];
    if (L == R)
      return new TreeNode(val);

    TreeNode *newNode = new TreeNode(val);
    int idx = umap[val];
    int leftLen = idx - L;
    newNode->left = helper(preorder, D + 1, L, idx - 1);
    newNode->right = helper(preorder, D + leftLen + 1, idx + 1, R);

    return newNode;
  }
};