class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();

    int i = 0, zero = 0, res = 0;
    for (int j = 0; j < n; ++j) {
      if (nums[j] == 0)
        zero++;
      while (zero > k) {
        if (nums[i] == 0)
          zero--;
        i++;
      }
      res = max(res, j - i + 1);
    }

    return res;
  }
};