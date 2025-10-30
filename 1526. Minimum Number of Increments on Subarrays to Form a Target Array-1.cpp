class Solution {
public:
  int minNumberOperations(vector<int> &target) {
    int prev = 0, res = 0;
    for (auto x : target) {
      res += max(0, x - prev);
      prev = x;
    }

    return res;
  }
};
