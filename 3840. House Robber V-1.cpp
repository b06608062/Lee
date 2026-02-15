class Solution {
public:
  long long rob(vector<int> &nums, vector<int> &colors) {
    int n = nums.size();

    vector<long long> f(n, 0);

    f[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      if (colors[i] == colors[i - 1])
        f[i] = max(f[i - 1], (i > 1 ? f[i - 2] : 0) + x);
      else
        f[i] = f[i - 1] + x;
    }

    return f[n - 1];
  }
};