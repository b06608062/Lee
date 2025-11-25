// quick sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    quickSort(nums, 0, n - 1);
    return nums;
  }

  void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;
    int p = partition(nums, l, r);
    quickSort(nums, l, p - 1);
    quickSort(nums, p + 1, r);
  }

  int partition(vector<int> &nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
      if (nums[j] < pivot)
        swap(nums[++i], nums[j]);
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
  }
};
