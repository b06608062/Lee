// mark
// 1529
// 線性時間選出兩個最大值
class Solution {
public:
  long long maxProduct(vector<int> &nums) {
    int mx = 0, mx2 = 0;
    for (auto x : nums) {
      x = abs(x);
      if (x > mx) {
        mx2 = mx;
        mx = x;
      } else if (x >= mx2)
        mx2 = x;
    }

    return 1ll * mx * mx2 * 1e5;
  }
};