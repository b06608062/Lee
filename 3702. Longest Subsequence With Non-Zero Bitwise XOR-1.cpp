// mark
// 1489
// XOR 性質 + 貪心
class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int n = nums.size();

    int total = 0;
    bool anyNonZero = false;
    for (int x : nums) {
      total ^= x;
      if (x != 0)
        anyNonZero = true;
    }

    if (total != 0)
      return n;
    if (anyNonZero)
      return n - 1;

    return 0;
  }
};

// Follow up
// 找最長子陣列使得 XOR 非 0
// Prefix XOR 性質 + 貪心
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int total = 0;
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
      total ^= nums[i];
      pref[i] = total;
    }

    // 整段 XOR 非 0，整段就是答案
    if (total != 0)
      return n;

    // total == 0 的情況
    int L = -1, R = -1;
    for (int i = 0; i < n; ++i) {
      if (pref[i] != 0) {
        if (L == -1)
          L = i;
        R = i;
      }
    }

    // 所有 prefix XOR 都是 0 → 全部元素都是 0 → 無解
    if (L == -1)
      return 0;

    // 子陣列 [i+1 .. n-1] 的 XOR 是 pref[n-1] ^ pref[i]
    int ans1 = n - 1 - L; // 保留 [L+1..n-1]
    // 子陣列 [0 .. i] 的 XOR 就是 pref[i]
    int ans2 = R + 1; // 保留 [0..R]
    return max(ans1, ans2);
  }
};
