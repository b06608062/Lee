// mark
// ???
// Greedy + Bit AND

class Solution {
public:
  int maximumAND(vector<int> &nums, int k, int m) {
    int n = nums.size();

    int res = 0;
    for (int i = 30; i >= 0; --i) {
      int t = res | (1 << i);
      vector<int> costs;
      for (auto x : nums) {
        int y = 0;
        for (int j = 30; j >= 0; --j) {
          if ((t & (1 << j)) || (y + ((1 << j) - 1) < x))
            y |= (1 << j);
        }
        costs.push_back(y - x);
      }
      sort(costs.begin(), costs.end());
      if (accumulate(costs.begin(), costs.begin() + m, 0ll) <= k)
        res = t;
    }

    return res;
  }
};