class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_set<int> uset;
    for (int i = n - 1; i >= 0; --i)
      if (nums[i] <= k) {
        uset.insert(nums[i]);
        if (uset.size() == k)
          return n - i;
      }

    return -1;
  }
};