// selection sort
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      int mn = i;
      for (int j = i + 1; j < n; ++j)
        if (nums[j] < nums[mn])
          mn = j;
      swap(nums[i], nums[mn]);
    }
    return nums;
  }
};