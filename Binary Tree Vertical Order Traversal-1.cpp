class Solution {
public:
  map<int, map<int, vector<int>>> mmap;
  vector<vector<int>> verticalOrder(TreeNode *root) {
    dfs(root, 0, 0);
    vector<vector<int>> res;
    for (auto &[_, rmap] : mmap) {
      res.push_back({});
      for (auto &[_, vec] : rmap)
        res.back().insert(res.back().end(), vec.begin(), vec.end());
    }

    return res;
  }

  void dfs(TreeNode *root, int row, int col) {
    if (!root)
      return;
    mmap[col][row].push_back(root->val);
    dfs(root->left, row + 1, col - 1);
    dfs(root->right, row + 1, col + 1);
  }
};
