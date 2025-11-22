class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int res = 0;
    for (auto x : nums)
      res += min(x % 3, 3 - (x % 3));

    return res;
  }
};