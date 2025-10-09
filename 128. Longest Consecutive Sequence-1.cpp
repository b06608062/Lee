class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> uset(nums.begin(), nums.end());

    int res = 0;
    for (int x : uset) {
      if (!uset.count(x - 1)) {
        int cur = x + 1;
        while (uset.count(cur))
          cur++;
        res = max(res, cur - x);
      }
    }

    return res;
  }
};
