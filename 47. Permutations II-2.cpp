class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  vector<int> used;
  vector<vector<int>> permuteUnique(vector<int> &nums) {
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

    unordered_set<int> uset;
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        if (uset.count(nums[i]))
          continue;
        uset.insert(nums[i]);
        path.push_back(nums[i]);
        used[i] = 1;
        helper(nums);
        path.pop_back();
        used[i] = 0;
      }
    }
  }
};