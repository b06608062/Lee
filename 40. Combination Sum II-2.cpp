class Solution {
public:
  vector<vector<int>> res;
  vector<int> subset;
  int sum;
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

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
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      int x = candidates[i];
      subset.push_back(x);
      sum += x;
      helper(candidates, target, i + 1);
      subset.pop_back();
      sum -= x;
    }
  }
};