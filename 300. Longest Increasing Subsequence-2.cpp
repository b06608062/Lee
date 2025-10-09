// patience sorting
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();

    vector<int> top(n);

    int piles = 1;
    top[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      int poker = nums[i];

      int left = 0, right = piles;
      while (left < right) {
        int mid = (left + right) / 2;
        if (top[mid] < poker)
          left = mid + 1;
        else
          right = mid;
      }

      if (left == piles)
        piles++;
      top[left] = poker;
    }

    return piles;
  }
};