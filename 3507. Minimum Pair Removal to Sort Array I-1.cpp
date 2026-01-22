class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size();
    while (nums.size() > 1) {
      int m = nums.size();
      bool valid = true;
      int mp = INT_MAX, idx = -1;
      for (int i = 0; i < m - 1; ++i) {
        int cur = nums[i] + nums[i + 1];
        if (cur < mp) {
          mp = cur;
          idx = i;
        }
        if (nums[i] > nums[i + 1])
          valid = false;
      }
      if (valid)
        break;
      nums.erase(nums.begin() + idx, nums.begin() + idx + 2);
      nums.insert(nums.begin() + idx, mp);
    }

    return n - nums.size();
  }
};