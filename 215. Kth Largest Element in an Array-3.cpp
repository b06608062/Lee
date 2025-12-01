class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    int tIdx = n - k;
    int l = 0, r = n - 1;
    while (true) {
      int pIdx = partition(nums, l, r);
      if (pIdx == tIdx)
        return nums[pIdx];
      else if (pIdx < tIdx)
        l = pIdx + 1;
      else
        r = pIdx - 1;
    }

    return -1;
  }

  int partition(vector<int> &nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j < r; ++j)
      if (nums[j] < pivot)
        swap(nums[++i], nums[j]);
    swap(nums[i + 1], nums[r]);
    return i + 1;
  }
};