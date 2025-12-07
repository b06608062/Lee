// mark
// 1701
// Sliding Window + 右指標擴張，左指標枚舉
class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    int maxN = *max_element(nums.begin(), nums.end());

    long long res = 0;
    int l = 0, cnt = 0;
    for (int r = 0; r < n; ++r) {
      if (nums[r] == maxN)
        cnt++;

      while (cnt >= k) {
        res += (n - r); // [l : r..n-1]
        if (nums[l++] == maxN)
          cnt--;
      }
    }

    return res;
  }
};
