class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();

    unordered_map<int, int> umap;
    vector<long long> pref(2 * n + 2);

    int cur = n + 1; // 0
    umap[0] = 1;
    pref[cur] = 1;

    long long res = 0;
    for (auto x : nums) {
      cur += x == target ? 1 : -1;
      res += pref[cur - 1];
      pref[cur] = ++umap[cur - n - 1] + pref[cur - 1];
    }

    return res;
  }
};