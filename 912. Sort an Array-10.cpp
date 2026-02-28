// LSD Radix Sort
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    // 1) 把帶符號整數映射到無符號的有序域：x ^ 0x80000000
    vector<uint32_t> a(n), b(n);
    for (int i = 0; i < n; ++i)
      a[i] = (uint32_t)nums[i] ^ 0x80000000u;
    // 2) 4 個位元組、每回合做一次穩定的 counting sort（基數 256）
    vector<int> cnt(256);
    for (int k = 0; k < 4; ++k) {
      fill(cnt.begin(), cnt.end(), 0);
      // 計數
      for (uint32_t v : a)
        ++cnt[(v >> (k * 8)) & 0xFF];
      // 前綴和 => 穩定排序位置
      for (int i = 1; i < 256; ++i)
        cnt[i] += cnt[i - 1];
      // 從後往前穩定放入
      for (int i = n - 1; i >= 0; --i) {
        uint32_t v = a[i];
        int d = (v >> (k * 8)) & 0xFF;
        b[--cnt[d]] = v;
      }
      // swap a, b
      a.swap(b);
    }
    // 3) 映射回帶符號整數
    for (int i = 0; i < n; ++i)
      nums[i] = (int32_t)(a[i] ^ 0x80000000u);
    return nums;
  }
};
