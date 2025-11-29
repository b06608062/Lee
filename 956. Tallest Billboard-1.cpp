class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    // dp[diff] = 在左右差為 diff 的情況下，較高那側的最大高度
    unordered_map<int, int> dp;
    dp[0] = 0; // 什麼都沒用時，左右都是 0

    for (int r : rods) {
      // 一定要先拷貝一份當前狀態，否則會在同一輪內互相污染
      auto cur = dp;

      for (auto &p : cur) {
        int diff = p.first;
        int taller = p.second;

        // 1. 不用這根 r：dp[diff] 已經在 dp 裡了，不用特別處理
        //    但後面其他轉移要往 dp 上寫

        // 2. 把 r 加到左邊
        int diff_left = diff + r;
        int taller_left = taller + r;
        if (!dp.count(diff_left) || dp[diff_left] < taller_left) {
          dp[diff_left] = taller_left;
        }

        // 3. 把 r 加到右邊
        int diff_right = abs(diff - r);
        int taller_right = taller + max(0, r - diff);
        if (!dp.count(diff_right) || dp[diff_right] < taller_right) {
          dp[diff_right] = taller_right;
        }
      }
    }

    // diff = 0 時，左右一樣高，taller 就是 billboard 高度
    return dp[0];
  }
};
