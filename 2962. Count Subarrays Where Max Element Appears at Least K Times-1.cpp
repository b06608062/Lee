class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int maxN = *max_element(nums.begin(), nums.end());
    unordered_map<int, long long> umap;
    umap[0] = 1;
    long long res = 0, cnt = 0;
    int cur = 0;
    for (auto x : nums) {
      if (x == maxN) {
        cur++;
        cnt += umap[cur - k];
        res += cnt;
        umap[cur]++;
      } else {
        res += cnt;
        umap[cur]++;
      }
    }

    return res;
  }
};