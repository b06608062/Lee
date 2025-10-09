// Sparse Table + Keep K Largest

struct Element {
  long long val;
  int i, j;
};

struct ST {
  vector<vector<pair<int, int>>> st; // min, max
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
  long long maxTotalValue(vector<int> &nums, int k) {
    int n = nums.size();

    ST st(nums);

    // max heap
    auto comp = [](auto &a, auto &b) { return a.val < b.val; };
    priority_queue<Element, vector<Element>, decltype(comp)> pq(comp);

    for (int i = 0; i < n; ++i) {
      auto [minVal, maxVal] = st.query(i, n - 1);
      pq.push({maxVal - minVal, i, n - 1});
    }

    long long res = 0;
    while (!pq.empty() && k > 0) {
      auto [val, i, j] = pq.top();
      pq.pop();
      res += val;
      k--;
      if (i < j) {
        auto [minVal, maxVal] = st.query(i, j - 1);
        pq.push({maxVal - minVal, i, j - 1});
      }
    }

    return res;
  }
};