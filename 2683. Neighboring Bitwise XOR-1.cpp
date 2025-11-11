class Solution {
public:
  bool doesValidArrayExist(vector<int> &derived) {
    int res = 0;
    for (auto x : derived)
      res ^= x;

    return res == 0;
  }
};