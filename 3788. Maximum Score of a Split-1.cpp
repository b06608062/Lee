class Solution {
public:
  long long maximumScore(vector<int> &nums) {
    int n = nums.size();

    vector<long long> suff(n + 1, LLONG_MAX);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = min((long long)nums[i], suff[i + 1]);

    long long cur = 0, res = LLONG_MIN;
    for (int i = 1; i < n; ++i) {
      cur += nums[i - 1];
      res = max(res, cur - suff[i]);
    }

    return res;
  }
};