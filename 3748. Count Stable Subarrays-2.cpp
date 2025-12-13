// mark
// 2209
// 將陣列切分為多個最大非遞增子序列區間，並預先計算每個區間的穩定子陣列數量前綴和
// 查詢時利用二分搜尋找到查詢區間內的完整子序列區間，就可以利用前綴和快速計算
// 可以把查詢區間 [l, r] 分為三個部分：包含 l 的左側部分、完整的中間部分、包含 r
// 的右側部分
// 搜尋目標： > l 的第一個 i 區間與 <= r 的最後一個區間 j
// 完整段落會落在 i 到 j - 1 區間
//  > l 的第一個 i 區間可以用 upper_bound(left, l) 搜尋到
//  <= r 的最後一個區間 j 可以用 upper_bound(left, r) - 1 搜尋到
class Solution {
public:
  vector<long long> countStableSubarrays(vector<int> &nums,
                                         vector<vector<int>> &queries) {
    int n = nums.size();

    vector<int> left;
    vector<long long> pref({0});
    int start = 0;
    for (int i = 0; i < n; ++i) {
      if (i == n - 1 || nums[i] > nums[i + 1]) {
        left.push_back(start);
        long long m = i - start + 1;
        pref.push_back(pref.back() + m * (m + 1) / 2);
        start = i + 1;
      }
    }

    vector<long long> res;
    for (auto &q : queries) {
      int l = q[0], r = q[1];
      // i = first start > l
      // j = last start <= r
      // 同段：i > j
      int i = upper_bound(left.begin(), left.end(), l) - left.begin();
      int j = upper_bound(left.begin(), left.end(), r) - left.begin() - 1;
      if (i > j) {
        long long m = r - l + 1;
        res.push_back(m * (m + 1) / 2);
      } else {
        long long m1 = left[i] - l;
        long long m2 = r - left[j] + 1;
        res.push_back(m1 * (m1 + 1) / 2 + (pref[j] - pref[i]) +
                      m2 * (m2 + 1) / 2);
      }
    }

    return res;
  }
};