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