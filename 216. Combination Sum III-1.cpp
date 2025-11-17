class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  int k;
  vector<vector<int>> combinationSum3(int k, int n) {
    this->k = k;

    dfs(9, n);

    return res;
  }

  void dfs(int i, int t) {
    if (t < 0)
      return;
    if (path.size() == k) {
      if (t == 0)
        res.push_back(path);
      return;
    }
    if (i + path.size() < k)
      return;

    for (int j = i; j > 0; --j) {
      path.push_back(j);
      dfs(j - 1, t - j);
      path.pop_back();
    }
  }
};