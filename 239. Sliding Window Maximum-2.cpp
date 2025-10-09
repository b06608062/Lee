// Sparse Table
struct ST {
  vector<vector<int>> st;
  vector<int> lg2;
  ST(vector<int> &nums) {
    int n = nums.size();

    lg2.resize(n + 1);
    for (int i = 2; i <= n; ++i)
      lg2[i] = lg2[i >> 1] + 1;

    int K = lg2[n] + 1;
    st = vector<vector<int>>(K, vector<int>(n, INT_MIN));

    for (int i = 0; i < n; ++i)
      st[0][i] = nums[i];

    for (int k = 1; k < K; ++k)
      for (int i = 0; i + (1 << k) - 1 < n; ++i)
        st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
  }

  int query(int l, int r) {
    int len = r - l + 1;
    int k = lg2[len];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    if (k == 1)
      return nums;

    ST st(nums);

    vector<int> res;
    for (int l = 0, r = k - 1; r < n; ++l, ++r)
      res.push_back(st.query(l, r));

    return res;
  }
};