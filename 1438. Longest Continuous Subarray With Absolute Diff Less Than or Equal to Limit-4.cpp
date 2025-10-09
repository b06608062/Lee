class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    deque<int> minDq, maxDq;

    int l = 0, res = 1;
    for (int r = 0; r < nums.size(); ++r) {
      while (!minDq.empty() && nums[minDq.back()] >= nums[r])
        minDq.pop_back();
      minDq.push_back(r);
      while (!maxDq.empty() && nums[maxDq.back()] <= nums[r])
        maxDq.pop_back();
      maxDq.push_back(r);

      while (nums[maxDq.front()] - nums[minDq.front()] > limit) {
        int maxIdx = maxDq.front(), minIdx = minDq.front();
        if (minIdx < maxIdx)
          minDq.pop_front();
        else
          maxDq.pop_front();
        l = min(minIdx, maxIdx) + 1;
      }

      res = max(res, r - l + 1);
    }

    return res;
  }
};