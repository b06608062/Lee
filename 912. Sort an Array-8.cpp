// shell sort
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; ++i) {
        int key = nums[i];
        int j = i - gap;
        while (j >= 0 && nums[j] > key) {
          nums[j + gap] = nums[j];
          j -= gap;
        }
        nums[j + gap] = key;
      }
    }
    return nums;
  }
};