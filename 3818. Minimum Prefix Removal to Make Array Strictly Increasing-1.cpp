class Solution {
public:
  int minimumPrefixLength(vector<int> &nums) {
    int n = nums.size();
    int i = n - 2;
    for (; i >= 0; --i) {
      if (nums[i + 1] <= nums[i]) {
        break;
      }
    }

    return i + 1;
  }
};