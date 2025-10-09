class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  vector<int> used;
  vector<vector<int>> permute(vector<int> &nums) {
    used = vector<int>(nums.size(), 0);
    helper(nums);

    return res;
  }

  void helper(vector<int> &nums) {
    int n = nums.size();
    if (path.size() == n) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        path.push_back(nums[i]);
        used[i] = 1;
        helper(nums);
        path.pop_back();
        used[i] = 0;
      }
    }
  }
};