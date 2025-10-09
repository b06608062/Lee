// bucket sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums;

    // 1) 動態偵測實際範圍
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    long long range = 1LL * mx - mn + 1;

    // 2) 設定桶數與桶寬（約 1000 個桶）
    const int TARGET_BUCKETS = 1024;
    long long width = max(1LL, (range + TARGET_BUCKETS - 1) / TARGET_BUCKETS);
    int nb = (int)((range + width - 1) / width); // 真正桶數 (ceil)

    vector<vector<int>> buckets(nb);

    // 3) 分配到桶
    for (int x : nums) {
      int idx = (int)((x - (long long)mn) / width); // 非負，因為減去 mn
      buckets[idx].push_back(x);
    }

    // 4) 每個桶內做插入排序（小桶效果通常最好；也可用 std::sort）
    auto insertionSort = [](vector<int> &a) {
      for (int i = 1; i < (int)a.size(); ++i) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
          a[j + 1] = a[j];
          j--;
        }
        a[j + 1] = key;
      }
    };
    for (auto &b : buckets)
      insertionSort(b);

    // 5) 回寫
    int k = 0;
    for (auto &b : buckets)
      for (int x : b)
        nums[k++] = x;

    return nums;
  }
};
