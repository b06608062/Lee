class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> uset;
    for (int i = 0; i < nums.size(); ++i) {
      if (i > k)
        uset.erase(nums[i - k - 1]);
      if (uset.count(nums[i]))
        return true;
      else
        uset.insert(nums[i]);
    }

    return false;
  }
};