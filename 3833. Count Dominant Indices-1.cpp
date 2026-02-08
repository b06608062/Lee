class Solution {
public:
  int dominantIndices(vector<int> &nums) {
    int n = nums.size();
    int cur = nums[n - 1], res = 0;
    for (int i = n - 2; i >= 0; --i) {
      int x = nums[i];
      if (x > (cur / (n - i - 1))) {
        res++;
      }
      cur += x;
    }

    return res;
  }
};