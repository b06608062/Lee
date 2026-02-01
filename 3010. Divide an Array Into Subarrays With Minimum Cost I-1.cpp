class Solution {
public:
  int minimumCost(vector<int> &nums) {
    sort(nums.begin() + 1, nums.end());
    return nums[0] + nums[1] + nums[2];
  }
};

class Solution {
public:
  int minimumCost(vector<int> &nums) {
    int n = nums.size();
    int min1 = 100, min2 = 100;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < min1) {
        min2 = min1;
        min1 = nums[i];
      } else if (nums[i] < min2) {
        min2 = nums[i];
      }
    }

    return nums[0] + min1 + min2;
  }
};
