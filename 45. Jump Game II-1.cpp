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

class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int cur = 0, next = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      if (i > cur) {
        cur = next;
        res++;
      }
      next = max(next, i + nums[i]);
    }

    return res;
  }
};