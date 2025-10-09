// quick sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);

    return nums;
  }

  void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;

    int p = nums[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
      while (nums[i] < p)
        i++;
      while (nums[j] > p)
        j--;
      if (i <= j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
    }

    quickSort(nums, l, j);
    quickSort(nums, i, r);
  }
};