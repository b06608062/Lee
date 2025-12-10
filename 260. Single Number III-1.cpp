// mark
// XOR 分組 + 位運算
// O(n)
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    long long ab = 0;
    for (long long x : nums)
      ab ^= x;
    long long lowbit = ab & (-ab);
    long long a = 0, b = 0;
    for (long long x : nums) {
      if (x & lowbit)
        a ^= x;
      else
        b ^= x;
    }

    return {(int)a, (int)b};
  }
};