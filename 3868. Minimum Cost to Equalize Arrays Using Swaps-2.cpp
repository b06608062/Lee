// mark
// ???
// 等價轉換題
// 1. 先把 nums1 和 nums2 的元素對應起來，然後統計每個元素在 nums1 和 nums2
// 中出現的次數差 diff
// 2. 如果 diff 是奇數，代表這個元素無法透過 swap 來平衡，直接回傳 -1
// 3. 只需要累加 diff > 0 的元素的 diff / 2

class Solution {
public:
  int minCost(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i) {
      int x1 = nums1[i], x2 = nums2[i];
      umap[x1]++;
      umap[x2]--;
    }
    int res = 0;
    for (auto &[_, diff] : umap)
      if (diff % 2)
        return -1;
      else if (diff > 0)
        res += diff / 2;
    return res;
  }
};