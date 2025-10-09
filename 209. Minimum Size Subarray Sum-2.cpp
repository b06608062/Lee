class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i - 1] + nums[i - 1];

    int res = n + 1;
    for (int r = 1; r <= n; ++r) {
      long long need = prefix[r] - target;
      int idx = upper_bound(prefix.begin(), prefix.begin() + r, need) -
                prefix.begin();
      if (idx > 0) {
        int l = idx - 1;
        res = min(res, r - l);
      }
    }

    return res == n + 1 ? 0 : res;
  }
};
