// merge sort
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
  }
  void mergeSort(vector<int> &nums, int l, int r) {
    if (l == r)
      return;
    int m = l + (r - l) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
  }
  void merge(vector<int> &nums, int l, int m, int r) {
    int n = r - l + 1;
    vector<int> temp(n);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
      if (nums[i] <= nums[j])
        temp[k++] = nums[i++];
      else
        temp[k++] = nums[j++];
    }
    while (i <= m)
      temp[k++] = nums[i++];
    while (j <= r)
      temp[k++] = nums[j++];
    for (int k = 0; k < n; ++k)
      nums[l + k] = temp[k];
  }
};