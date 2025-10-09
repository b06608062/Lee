// insert sort
// TLE

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    for (int i = 1; i < n; ++i) {
      int p = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > p) {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = p;
    }

    return nums;
  }
};