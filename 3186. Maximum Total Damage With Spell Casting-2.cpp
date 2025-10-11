class Solution {
public:
  long long maximumTotalDamage(vector<int> &power) {
    unordered_map<int, long long> umap;
    for (auto x : power)
      umap[x] += x;

    int n = umap.size();

    vector<int> arr;
    for (auto [k, _] : umap)
      arr.push_back(k);
    sort(arr.begin(), arr.end());

    vector<long long> dp(n, 0);

    dp[0] = umap[arr[0]];
    for (int i = 1; i < n; ++i) {
      long long x = umap[arr[i]];
      long long take = x;
      int prev = upper_bound(arr.begin(), arr.begin() + i, arr[i] - 3) -
                 arr.begin() - 1;
      if (prev >= 0)
        take += dp[prev];
      dp[i] = max(dp[i - 1], take);
    }

    return dp[n - 1];
  }
};