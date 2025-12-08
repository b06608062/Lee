// mark
// 1656
// Sliding Window
// 維護 Window Size 中 1 出現過的最高頻率
// Window Size 只增不減，當元素種類很多時，可以避免每次都要重新計算頻率
class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();

    int cnt[2];
    int i = 0, j = 0, maxFreq = 0;
    while (j < n) {
      cnt[nums[j]]++;
      maxFreq = max(maxFreq, cnt[1]);
      if (maxFreq + k < j - i + 1)
        cnt[nums[i++]]--;
      j++;
    }

    return min(maxFreq + k, n);
  }
};