// selection sort
// TLE

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
      int minIdx = i;
      for (int j = i + 1; j < n; ++j)
        if (nums[j] < nums[minIdx])
          minIdx = j;
      swap(nums[i], nums[minIdx]);
    }

    return nums;
  }
};