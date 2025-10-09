class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    multiset<int> mset;

    int l = 0, res = 1;
    for (int r = 0; r < nums.size(); ++r) {
      mset.insert(nums[r]);
      while (*mset.rbegin() - *mset.begin() > limit) {
        auto it = mset.find(nums[l]);
        mset.erase(it);
        l++;
      }
      res = max(res, r - l + 1);
    }

    return res;
  }
};