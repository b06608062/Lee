// mark
// 1585
// 數學 + 分類討論
class Solution {
public:
  int maximumSum(vector<int> &nums) {
    // 3n, 3n, 3n
    // 3n + 1, 3n + 1, 3n + 1
    // 3n + 2, 3n + 2, 3n + 2
    // 3n, 3n + 1, 3n + 2

    vector<vector<int>> arr(3);
    for (auto x : nums)
      arr[x % 3].push_back(x);

    int res = 0;
    for (auto &a : arr) {
      sort(a.rbegin(), a.rend());
      if (a.size() >= 3) {
        res = max(res, accumulate(a.begin(), a.begin() + 3, 0));
      }
    }

    if (!arr[0].empty() && !arr[1].empty() && !arr[2].empty())
      res = max(res, arr[0][0] + arr[1][0] + arr[2][0]);

    return res;
  }
};