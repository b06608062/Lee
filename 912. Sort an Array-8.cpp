// shell sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; ++i) {
        int p = nums[i];
        int j = i - gap;
        while (j >= 0 && nums[j] > p) {
          nums[j + gap] = nums[j];
          j -= gap;
        }
        nums[j + gap] = p;
      }
    }

    return nums;
  }
};