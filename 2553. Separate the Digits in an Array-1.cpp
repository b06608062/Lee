class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    vector<int> res;
    for (auto x : nums) {
      vector<int> temp;
      while (x) {
        temp.push_back(x % 10);
        x /= 10;
      }
      res.insert(res.end(), temp.rbegin(), temp.rend());
    }

    return res;
  }
};