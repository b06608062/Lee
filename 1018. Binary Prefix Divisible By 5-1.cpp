class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &nums) {
    vector<bool> res;
    int cur = 0;
    for (auto x : nums) {
      cur = cur << 1 | x;
      cur %= 5;
      res.push_back(cur % 5 == 0);
    }

    return res;
  }
};