class Solution {
public:
  vector<long long> countStableSubarrays(vector<int> &nums,
                                         vector<vector<int>> &queries) {
    int n = nums.size();

    // 尋找「嚴格遞增段」
    vector<int> left; // 每個遞增段的左端點
    vector<long long> s = {0}; // 遞增子陣列個數的前綴和（注意每段是 m*(m+1)/2）
    int start = 0; // 當前遞增段的起點

    for (int i = 0; i < n; i++) {
      int x = nums[i];

      // 若到最後一個元素，或出現 nums[i] > nums[i+1]，表示遞增段結束
      if (i == n - 1 || x > nums[i + 1]) {
        // 目前找到一段嚴格遞增區間 [start, i]
        left.push_back(start);
        long long m = i - start + 1;

        // 長度為 m 的嚴格遞增段，其遞增子陣列總數為 m*(m+1)/2
        // 並累加到前綴和中
        s.push_back(s.back() + m * (m + 1) / 2);

        // 下一段從 i+1 開始
        start = i + 1;
      }
    }

    vector<long long> ans;
    ans.reserve(queries.size()); // 預先配置空間

    for (auto &q : queries) {
      int l = q[0], r = q[1];

      // i：第一個 left[i] > l 的段索引（右界）
      int i = ranges::upper_bound(left, l) - left.begin();

      // j：最後一個 left[j] <= r 的段索引（左界）
      int j = ranges::upper_bound(left, r) - left.begin() - 1;

      // 若 i > j，表示 l 與 r 落在同一個遞增段中
      if (i > j) {
        long long m = r - l + 1;        // 該段長度
        ans.push_back(m * (m + 1) / 2); // 該段全部子陣列
        continue;
      }

      // 若 l 與 r 不在同一段，區間被分成三段：
      // 1. 左邊殘段 [l, left[i])
      // 2. 中間完整段 [left[i], left[j])（可用前綴和求）
      // 3. 右邊殘段 [left[j], r]

      long long m1 = left[i] - l;     // 左邊殘段長度
      long long m3 = r - left[j] + 1; // 右邊殘段長度

      long long mid = s[j] - s[i]; // 中間完整段的遞增子陣列總數（用前綴和）

      // 三段相加：m*(m+1)/2 為遞增子陣列公式
      ans.push_back(m1 * (m1 + 1) / 2 + mid + m3 * (m3 + 1) / 2);
    }

    return ans;
  }
};
