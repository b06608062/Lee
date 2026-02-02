/**
 * // 核心目標：最小化子陣列代價總和，單個子陣列代價公式為 (sum * (sum + 1)) / 2 
 * // 數學特性：代價函數 f(S) 為凸函數 (f''(S) = 1 > 0)，滿足四邊形不等式 (QI):
 * //           w(j, i) + w(j', i') <= w(j, i') + w(j', i),  其中 j < j' < i < i'
 * // 
 * // 核心證明：為什麼 opt[i] <= opt[i+1] (決策單調性)
 * //   1. 設 H(j, i) = dp[p-1][j-1] + w(j, i)，其中 w(j, i) 為子陣列 [j, i] 的代價。
 * //   2. 令 opt[i] 為使 H(j, i) 最小的決策點 j。
 * //   3. 由 QI 移項得：w(j, i') - w(j', i') >= w(j, i) - w(j', i)
 * //   4. 比較在長度 i' 時，決策點 j 與 j' 的優劣：
 * //      H(j, i') - H(j', i') = (dp[p-1][j-1] - dp[p-1][j'-1]) + (w(j, i') - w(j', i'))
 * //   5. 代入第 3 步：H(j, i') - H(j', i') >= (dp[p-1][j-1] - dp[p-1][j'-1]) + (w(j, i) - w(j', i))
 * //      => H(j, i') - H(j', i') >= H(j, i) - H(j', i)
 * //   6. 結論：若 j' 在 i 處優於 j (H(j, i) - H(j', i) >= 0)，則在更大的 i' 處 j' 必優於 j。
 * //      因此，最佳分割點 opt[i] 隨 i 增加而單調遞增，不會往回跳。
 * // 
 * // 優化策略：Divide and Conquer (D&C) 在每一層分割 p 透過遞迴中點 mid 尋找 best_j，
 * //           並利用單調性將搜尋空間從 O(N^2) 修剪至 O(N log N)。
 */

class Solution {
  vector<long long> pref;
  vector<vector<long long>> dp;
  const long long INF = LLONG_MAX / 2;

  // 分治函數：計算第 p 個分割時，dp[L...R][p] 的最優解
  // optL, optR 是決策點 j 的搜尋範圍
  void compute(int p, int L, int R, int optL, int optR) {
    if (L > R)
      return;

    int mid = L + (R - L) / 2;
    int best_j = -1;

    // 在 [optL, min(mid, optR)] 範圍內尋找最優分割點 j
    // j 代表第 p 個子陣列的起始索引 (1-indexed)
    for (int j = optL; j <= min(mid, optR); ++j) {
      long long sum_val = pref[mid] - pref[j - 1];
      long long cur_cost = sum_val * (sum_val + 1) / 2;

      // 轉移方程式: dp[mid][p] = min(dp[j-1][p-1] + cur_cost)
      if (dp[j - 1][p - 1] + cur_cost < dp[mid][p]) {
        dp[mid][p] = dp[j - 1][p - 1] + cur_cost;
        best_j = j;
      }
    }

    // 核心：利用決策單調性 opt[mid][p] <= opt[mid+1][p]
    // 左半部搜尋範圍限制在 [optL, best_j]
    compute(p, L, mid - 1, optL, best_j);
    // 右半部搜尋範圍限制在 [best_j, optR]
    compute(p, mid + 1, R, best_j, optR);
  }

public:
  long long minPartitionScore(vector<int> &nums, int k) {
    int n = nums.size();
    pref.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }

    // 初始化 DP 表
    dp.assign(n + 1, vector<long long>(k + 1, INF));
    dp[0][0] = 0;

    // 第一層 p=1 可以直接初始化，也可以跑分治
    for (int i = 1; i <= n; ++i) {
      long long s = pref[i];
      dp[i][1] = s * (s + 1) / 2;
    }

    // 從第 2 個分割開始應用 D&C 優化
    for (int p = 2; p <= k; ++p) {
      // 對於固定的 p，在區間 [p, n] 內計算 dp[i][p]
      // 分割點 j 的合法範圍是 [p, n]
      compute(p, p, n, p, n);
    }

    return dp[n][k];
  }
};