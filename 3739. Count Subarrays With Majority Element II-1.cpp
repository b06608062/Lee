// O(n) time complexity
class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();

    unordered_map<int, int> umap;
    umap[0] = 1;

    long long cur = 0, prev = 0, res = 0;
    for (auto x : nums) {
      if (x == target) {
        prev += umap[cur++];
        res += prev;
      } else {
        prev -= umap[--cur];
        res += prev;
      }
      umap[cur]++;
    }

    return res;
  }
};