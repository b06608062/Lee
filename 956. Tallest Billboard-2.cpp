class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    int n = rods.size();
    int sum = 0;
    for (int x : rods)
      sum += x;

    // diff 可能介於 [-sum, sum]，用 offset 把它平移到 [0, 2*sum]
    int offset = sum;

    // memo[i][diffIndex] = dfs(i, diff) 的結果
    // 用 INT_MIN 表示「還沒算過」
    vector<vector<int>> memo(n, vector<int>(2 * sum + 1, INT_MIN));

    const int NEG_INF = -1000000000;

    function<int(int, int)> dfs = [&](int i, int diff) -> int {
      if (i == n) {
        // 所有 rods 都用完了，如果差為 0 才是合法解
        return (diff == 0) ? 0 : NEG_INF;
      }
      int idx = diff + offset;
      int &res = memo[i][idx];
      if (res != INT_MIN)
        return res;

      int r = rods[i];

      // 1. 不用這根 rod
      int best = dfs(i + 1, diff);

      // 2. 放到左邊
      best = max(best, r + dfs(i + 1, diff + r));

      // 3. 放到右邊
      best = max(best, r + dfs(i + 1, diff - r));

      return res = best;
    };

    int totalUsed = dfs(0, 0);
    if (totalUsed < 0)
      return 0;           // 沒有合法的平衡方案
    return totalUsed / 2; // 左右一樣高，各是 totalUsed / 2
  }
};
