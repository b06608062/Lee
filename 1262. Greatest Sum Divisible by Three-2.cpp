class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> f(3);
    for (auto x : nums)
      f[x % 3].push_back(x);
    for (int i = 1; i < 3; ++i)
      sort(f[i].begin(), f[i].end());

    if (sum % 3 == 0)
      return sum;

    int case1 = INT_MAX, case2 = INT_MAX;
    if (sum % 3 == 1) {
      if (f[1].size() >= 1)
        case1 = f[1][0];
      if (f[2].size() >= 2)
        case2 = f[2][0] + f[2][1];
    } else {
      if (f[1].size() >= 2)
        case1 = f[1][0] + f[1][1];
      if (f[2].size() >= 1)
        case2 = f[2][0];
    }

    return max(sum - case1, sum - case2);
  }
};