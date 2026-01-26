class Solution {
public:
  vector<int> rotateElements(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> arr;
    for (auto x : nums) {
      if (x >= 0) {
        arr.push_back(x);
      }
    }

    int m = arr.size();
    if (m == 0)
      return nums;
    int r = m - (k % m);
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + r);
    reverse(arr.begin() + r, arr.end());

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= 0) {
        nums[i] = arr[j++];
      }
    }

    return nums;
  }
};