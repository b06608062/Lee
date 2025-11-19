class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int k = nums.size();
    vector<int> cnt(k, 0);
    vector<pair<int, int>> arr;
    for (int i = 0; i < k; ++i) {
      auto &v = nums[i];
      for (auto x : v)
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int bestL = arr[0].first, bestR = arr[n - 1].first;
    int covered = 0;
    int l = 0, r = 0;
    while (r < n) {
      auto &[x, i] = arr[r];
      if (++cnt[i] == 1)
        covered++;
      while (covered == k) {
        auto &[y, j] = arr[l++];
        if (x - y < bestR - bestL)
          bestL = y, bestR = x;
        if (--cnt[j] == 0)
          covered--;
      }
      r++;
    }

    return {bestL, bestR};
  }
};