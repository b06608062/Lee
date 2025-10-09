class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();

    vector<int> arr(n, 1);

    for (int i = 1; i < n; ++i)
      arr[i] = arr[i - 1] * nums[i - 1];

    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
      arr[i] *= rightProduct;
      rightProduct *= nums[i];
    }

    return arr;
  }
};