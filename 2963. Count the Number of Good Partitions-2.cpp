class Solution {
public:
  int numberOfGoodPartitions(vector<int> &nums) {
    const int MOD = 1e9 + 7;
    int n = nums.size();

    unordered_map<int, int> left, right;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (!left.count(x))
        left[x] = i;
      right[x] = i;
    }

    vector<int> diff(n, 0);
    for (auto [x, ldix] : left) {
      diff[ldix]++;
      diff[right[x]]--;
    }

    int cur = 0, res = 1;
    for (int i = 0; i < n - 1; ++i) {
      cur += diff[i];
      if (cur == 0) {
        res <<= 1;
        if (res >= MOD)
          res %= MOD;
      }
    }

    return res;
  }
};