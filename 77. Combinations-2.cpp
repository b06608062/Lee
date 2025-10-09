class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  vector<vector<int>> combine(int n, int k) {
    helper(n, k, 1);

    return res;
  }

  void helper(int n, int k, int start) {
    if (subset.size() == k) {
      res.push_back(subset);
      return;
    }

    for (int i = start; i <= n; ++i) {
      subset.push_back(i);
      helper(n, k, i + 1);
      subset.pop_back();
    }
  }
};