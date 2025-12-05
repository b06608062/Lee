class Solution {
public:
  int countPartitions(vector<int> &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int cur = 0, res = 0;
    for (int i = 0; i < n - 1; ++i) {
      cur += nums[i];
      if (((sum - cur) - cur) % 2 == 0)
        res++;
    }

    return res;
  }
};