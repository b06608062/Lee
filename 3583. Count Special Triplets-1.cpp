class Solution {
public:
  int specialTriplets(vector<int> &nums) {
    const int MOD = 1e9 + 7;
    int n = nums.size();
    vector<int> left(n, 0), right(n, 0);
    unordered_map<int, int> lm, rm;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      left[i] = lm[x * 2];
      lm[x]++;
    }
    for (int i = n - 1; i >= 0; --i) {
      int x = nums[i];
      right[i] = rm[x * 2];
      rm[x]++;
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      res += 1ll * left[i] * right[i];
      res %= MOD;
    }

    return (int)res;
  }
};