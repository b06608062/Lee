class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int left = 0, right = 0, cnt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      cnt++;
      if (i < n - 1 && nums[i] == nums[i + 1])
        continue;
      int x = nums[i];
      while (nums[left] < x - k)
        left++;
      while (right < n && nums[right] <= x + k)
        right++;
      res = max(res, min(cnt + numOperations, right - left));
      cnt = 0;
    }

    if (res >= numOperations)
      return res;

    left = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      while (nums[left] < x - k * 2)
        left++;
      res = max(res, min(numOperations, i - left + 1));
    }

    return res;
  }
};