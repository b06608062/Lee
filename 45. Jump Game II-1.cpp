class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();

    int i = 0, maxReachable = 0, lastJumpedPos = 0, res = 0;
    while (lastJumpedPos < n - 1) {
      maxReachable = max(maxReachable, i + nums[i]);
      if (i == lastJumpedPos) {
        lastJumpedPos = maxReachable;
        res++;
      }
      i++;
    }

    return res;
  }
};