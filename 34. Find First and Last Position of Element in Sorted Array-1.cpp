class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int first = -1, last = -1;
    for (int i = 0; i < n; ++i)
      if (nums[i] == target) {
        first = i;
        while (i + 1 < n && nums[i + 1] == target)
          i++;
        last = i;
        break;
      }

    return {first, last};
  }
};