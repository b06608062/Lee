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
      long long best = max(dp[i - 1], x);
      if (arr[i] - arr[i - 1] > 2)
        best = dp[i - 1] + x;
      else if (i - 2 >= 0 && arr[i] - arr[i - 2] > 2)
        best = max(best, dp[i - 2] + x);
      else if (i - 3 >= 0)
        best = max(best, dp[i - 3] + x);
      dp[i] = best;
    }

    return dp[n - 1];
  }
};