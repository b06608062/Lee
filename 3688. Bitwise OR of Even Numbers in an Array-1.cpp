class Solution {
public:
  int evenNumberBitwiseORs(vector<int> &nums) {
    int res = 0;
    for (auto x : nums)
      if (x % 2 == 0)
        res |= x;

    return res;
  }
};