// mark
// 1585
// 三維 DP + MOD + 選取數字
// MOD 要先確認前一個狀態有沒有值，才能進行轉移
class Solution {
public:
  int maximumSum(vector<int> &nums) {
    const int INF = INT_MIN / 2;
    vector f(3 + 1, vector<int>(3, INF));

    f[0][0] = 0;
    for (auto x : nums)
      for (int j = 3; j > 0; j--)
        for (int k = 0; k < 3; ++k)
          f[j][(x + k) % 3] = max(f[j][(x + k) % 3], f[j - 1][k % 3] + x);

    return max(f[3][0], 0);
  }
};