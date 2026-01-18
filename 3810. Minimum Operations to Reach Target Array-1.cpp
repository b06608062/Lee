class Solution {
public:
  int minOperations(vector<int> &nums, vector<int> &target) {
    int n = nums.size();
    unordered_set<int> uset;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != target[i])
        uset.insert(nums[i]);
    }

    return uset.size();
  }
};