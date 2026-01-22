class Solution {
public:
  vector<int> minBitwiseArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;
    for (auto x : nums) {
      if (x == 2) {
        res.push_back(-1);
      } else {
        int cnt = 0;
        while (x >> cnt & 1) {
          cnt++;
        }
        int ans = x ^ (1 << (cnt - 1));
        res.push_back(ans);
      }
    }

    return res;
  }
};