class Solution {
public:
  int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    sort(divisors.begin(), divisors.end());

    int res = -1, curMax = -1;
    for (auto d : divisors) {
      int cnt = 0;
      for (auto x : nums)
        if (x % d == 0)
          cnt++;
      if (cnt > curMax) {
        curMax = cnt;
        res = d;
      }
    }

    return res;
  }
};