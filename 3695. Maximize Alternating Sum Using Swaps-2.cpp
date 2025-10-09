struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
    int n = nums.size();

    DSU dsu(n);

    for (auto &swap : swaps)
      dsu.unite(swap[0], swap[1]);

    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < n; ++i)
      umap[dsu.find(i)].push_back(i);

    long long res = 0;
    for (auto &[_, v] : umap) {
      int size = v.size(), even = 0;
      vector<int> arr(size);
      for (int i = 0; i < size; ++i) {
        int pos = v[i];
        if ((pos & 1) == 0)
          ++even;
        arr[i] = nums[pos];
      }

      // sumAll, lo, hi
      long long sumAll = 0;
      int lo = INT_MAX, hi = INT_MIN;
      for (auto x : arr) {
        sumAll += x;
        lo = min(lo, x);
        hi = max(hi, x);
      }

      if (even == 0) {
        res -= sumAll;
        continue;
      }
      if (even == size) {
        res += sumAll;
        continue;
      }

      int l = lo, r = hi;
      while (l < r) {
        int m = l + (r - l + 1) / 2;
        int cnt = 0;
        for (auto x : arr)
          if (x >= m)
            cnt++;
        if (cnt < even)
          r = m - 1;
        else
          l = m;
      }

      long long sumEven = 0;
      for (auto x : arr)
        if (x > l) {
          sumEven += x;
          even--;
        }
      sumEven += even * (long long)l;
      res += sumEven - (sumAll - sumEven);
    }

    return res;
  }
};
