class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;

    int target = sum / 2;
    unordered_set<int> uset, temp;

    uset.insert(0);
    for (auto x : nums) {
      temp = uset;
      for (auto i : temp)
        uset.insert(i + x);
    }

    return uset.count(target);
  }
};