class Solution {
  pair<tuple<int, int, int>, bool> primeFactorization(long long k) {
    int e2 = countr_zero((uint64_t)k);
    k >>= e2;

    int e3 = 0;
    while (k % 3 == 0) {
      e3++;
      k /= 3;
    }

    int e5 = 0;
    while (k % 5 == 0) {
      e5++;
      k /= 5;
    }

    return {tuple(e2, e3, e5), k == 1};
  }

public:
  int countSequences(vector<int> &nums, long long k) {
    auto [e, ok] = primeFactorization(k);
    if (!ok) {
      return 0;
    }

    int n = nums.size();
    vector<tuple<int, int, int>> es(n);
    for (int i = 0; i < n; i++)
      es[i] = primeFactorization(nums[i]).first;

    unordered_map<int, int> memo;

    auto dfs = [&](this auto &&dfs, int i, int e2, int e3, int e5) -> int {
      if (i < 0)
        return e2 == 0 && e3 == 0 && e5 == 0;

      int key = i << 18 | (e2 + n * 2) << 12 | (e3 + n) << 6 | (e5 + n);
      auto it = memo.find(key);
      if (it != memo.end()) {
        return it->second;
      }

      auto [x, y, z] = es[i];
      int res1 = dfs(i - 1, e2 - x, e3 - y, e5 - z); // k 除以 nums[i]
      int res2 = dfs(i - 1, e2 + x, e3 + y, e5 + z); // k 乘以 nums[i]
      int res3 = dfs(i - 1, e2, e3, e5);             // k 不變
      int res = res1 + res2 + res3;

      memo[key] = res;
      return res;
    };

    auto [e2, e3, e5] = e;
    return dfs(n - 1, e2, e3, e5);
  }
};