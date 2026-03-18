class Solution {
public:
  int jump(vector<int> &nums) {
    int n = nums.size();
    int cur = 0, nxt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      if (i > cur) {
        cur = nxt;
        res++;
      }
      nxt = max(nxt, i + nums[i]);
    }

    return res;
  }
};