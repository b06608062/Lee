// mark
// 2557
// Two-pointer + Prefix Zero Recording + √n 剪枝
class Solution {
public:
  int numberOfSubstrings(string s) {
    vector<int> pos0 = {-1}; // 加上一個 -1 的哨兵位置，方便在計算 cnt0
                             // 達到某值時統一處理子串區間
    int total1 = 0; // [0, r] 範圍內目前累積的 '1' 的數量
    int res = 0;

    for (int r = 0; r < s.size(); r++) {
      if (s[r] == '0') {
        pos0.push_back(r); // 若是 '0'，記錄其索引位置
      } else {
        total1++;               // 若是 '1'，累加 total1
        res += r - pos0.back(); // 計算不含 '0' 的子串數量：所有以 r
                                // 為結尾且沒有 '0' 的子串
      }

      int m = pos0.size();
      // 自後往前遍歷 pos0，若 pos0 的大小為 m，則 i 後面的 0 的數量 = (m - i)
      for (int i = m - 1; i > 0 && (m - i) * (m - i) <= total1; i--) {
        int p = pos0[i - 1]; // 上一個 0 的位置
        int q = pos0[i];     // 當前這個 0 的位置
        int cnt0 = m - i;    // 子串中 0 的個數

        // [q, r] 之間 1 的數量：區間長度 (r - q + 1) 減掉包含的 0 數量
        int cnt1 = r - q + 1 - cnt0;

        // 子串起點 l 可選的範圍是 [p+1, q]
        // 需滿足 cnt1 + (q - l) >= cnt0 * cnt0
        // 轉換後得 l >= q - max(cnt0 * cnt0 - cnt1, 0)
        // lmax = q - max(cnt0 * cnt0 - cnt1, 0)
        // [p + 1, lmax] 的長度即為可行子串數量
        res += max(q - max(cnt0 * cnt0 - cnt1, 0) - (p + 1) + 1, 0);
      }
    }

    return res;
  }
};
