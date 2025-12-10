// mark
// 2248
// 模運算前綴和 + 延遲更新哈希表避免重複元素重複統計
// nums 已排序，因此同一段重複元素會產生大量「值一樣、位置不同」的子陣列，
// 例如 [3,3,3] 有三個 [3]、兩個 [3,3]，但都算同一種，只能統計一次
class Solution {
public:
  long long numGoodSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> umap;
    umap[0] = 1;

    int lastStart = 0;
    long long cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (i > 0 && x != nums[i - 1]) {
        long long prev = cur;
        int v = nums[i - 1];
        for (int j = i - 1; j >= lastStart; --j) {
          umap[prev % k]++;
          prev -= v;
        }
        lastStart = i;
      }
      cur += x;
      res += umap[cur % k];
    }

    return res;
  }
};