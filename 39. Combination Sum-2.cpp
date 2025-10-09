class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  int sum;
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sum = 0;
    helper(candidates, target, 0);

    return res;
  }

  void helper(vector<int> &candidates, int target, int start) {
    if (sum == target) {
      res.push_back(subset);
      return;
    }

    if (sum > target)
      return;

    for (int i = start; i < candidates.size(); ++i) {
      int x = candidates[i];
      subset.push_back(x);
      sum += x;
      helper(candidates, target, i);
      subset.pop_back();
      sum -= x;
    }
  }
};