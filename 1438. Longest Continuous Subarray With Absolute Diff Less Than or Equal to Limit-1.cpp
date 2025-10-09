// Sparse Table + Binary Search
struct ST {
  vector<vector<pair<int, int>>> st;
  vector<int> lg2;
  ST(vector<int> &nums) {
    int n = nums.size();

    lg2.resize(n + 1);
    for (int i = 2; i <= n; ++i)
      lg2[i] = lg2[i >> 1] + 1;

    int K = lg2[n] + 1;
    st = vector<vector<pair<int, int>>>(K, vector<pair<int, int>>(n));

    for (int i = 0; i < n; ++i)
      st[0][i] = {nums[i], nums[i]};

    for (int k = 1; k < K; ++k)
      for (int i = 0; i + (1 << k) - 1 < n; ++i) {
        auto [lMin, lMax] = st[k - 1][i];
        auto [rMin, rMax] = st[k - 1][i + (1 << (k - 1))];
        st[k][i] = {min(lMin, rMin), max(lMax, rMax)};
      }
  }

  pair<int, int> query(int l, int r) {
    int len = r - l + 1;
    int k = lg2[len];
    auto [lMin, lMax] = st[k][l];
    auto [rMin, rMax] = st[k][r - (1 << k) + 1];
    return {min(lMin, rMin), max(lMax, rMax)};
  }
};

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();

    ST st(nums);

    auto helper = [&](int len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        auto [minVal, maxVal] = st.query(i, i + len - 1);
        if (maxVal - minVal <= limit)
          return true;
      }

      return false;
    };

    int l = 2, r = n + 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (helper(m))
        l = m + 1;
      else
        r = m;
    }

    return l - 1;
  }
};