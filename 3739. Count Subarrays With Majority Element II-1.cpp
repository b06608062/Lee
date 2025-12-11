// mark
// 2090
// 差分前綴和 + 哈希表 + 利用差分連續性維護 cnt
class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    unordered_map<long long, int> umap;

    umap[0]++;
    long long cur = 0, res = 0;
    int cnt = 0;
    for (auto x : nums) {
      if (x == target)
        cnt += umap[cur++];
      else
        cnt -= umap[--cur];
      res += cnt;
      umap[cur]++;
    }

    return res;
  }
};