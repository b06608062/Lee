class Solution {
public:
  int minRemoval(vector<int> &nums, int k) {
    int n = nums.size();
    long long mx = *max_element(nums.begin(), nums.end()) + 1;
    sort(nums.begin(), nums.end());

    int res = n;
    for (int i = 0; i < n; ++i) {
      if (i >= res) {
        break;
      }
      int kx = min(mx, 1ll * nums[i] * k + 1);
      int j = lower_bound(nums.begin() + i, nums.end(), kx) - nums.begin();
      res = min(res, i + (n - j));
    }
    return res;
  }
};