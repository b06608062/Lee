class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int n = nums.size();

    int total = 0;
    bool anyNonZero = false;
    for (int x : nums) {
      total ^= x;
      if (x != 0)
        anyNonZero = true;
    }

    if (total != 0)
      return n;
    if (anyNonZero)
      return n - 1;

    return 0;
  }
};
