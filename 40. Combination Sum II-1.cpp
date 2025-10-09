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

  void helper(vector<int> &candidates, int target, int i) {
    if (sum == target) {
      res.push_back(subset);
      return;
    }

    if (sum > target || i == candidates.size())
      return;

    int x = candidates[i];
    subset.push_back(x);
    sum += x;
    helper(candidates, target, i + 1);
    subset.pop_back();
    sum -= x;
    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
      i++;
    helper(candidates, target, i + 1);
  }
};