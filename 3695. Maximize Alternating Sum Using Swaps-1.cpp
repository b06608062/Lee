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
        if (pos % 2 == 0)
          even++;
        arr[i] = nums[pos];
      }
      sort(arr.rbegin(), arr.rend());
      for (int i = 0; i < size; ++i)
        if (i < even)
          res += arr[i];
        else
          res -= arr[i];
    }

    return res;
  }
};