// mark
// ???
// XOR Prefix Sum + 哈希表計數 + 動態規劃
class Solution {
public:
  int alternatingXOR(vector<int> &nums, int target1, int target2) {
    int n = nums.size();
    const int MOD = 1e9 + 7;
    unordered_map<int, long long> umap1; // 前綴為 S，且結尾為 target1 的方案數
    unordered_map<int, long long> umap2; // 前綴為 S，且結尾為 target2 的方案數
    umap2[0] = 1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur ^= nums[i];
      int last1 = umap2[cur ^ target1];
      int last2 = umap1[cur ^ target2];
      if (i == n - 1)
        return last1 + last2;
      umap1[cur] = (umap1[cur] + last1) % MOD;
      umap2[cur] = (umap2[cur] + last2) % MOD;
    }

    return -1;
  }
};