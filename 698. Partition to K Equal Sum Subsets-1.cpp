class Solution {
public:
  int k, target;
  vector<int> used;
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
      return false;

    this->k = k;
    target = sum / k;
    used = vector<int>(nums.size(), 0);

    sort(nums.rbegin(), nums.rend());

    return helper(nums, 0, 0, 0);
  }

  bool helper(vector<int> &nums, int group, int curSum, int start) {
    if (group == k)
      return true;
    if (curSum == target)
      return helper(nums, group + 1, 0, 0);
    else if (curSum > target)
      return false;

    unordered_set<int> uset;
    for (int i = start; i < nums.size(); ++i) {
      int x = nums[i];
      if (!used[i] && !uset.count(x)) {
        used[i] = 1;
        uset.insert(x);
        if (helper(nums, group, curSum + x, i + 1))
          return true;
        used[i] = 0;
      }
    }

    return false;
  }
};