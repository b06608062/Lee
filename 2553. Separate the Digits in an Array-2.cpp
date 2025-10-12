class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> res;
    for (auto x : nums) {
      string s = to_string(x);
      for (auto ch : s)
        res.push_back(ch - '0');
    }

    return res;
  }
};