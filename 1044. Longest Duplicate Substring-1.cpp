// mark
// 2429
// Binary Search + Rolling Hash + 哈希表儲存起始位置 + 字串比較確認
class Solution {
public:
  const int MOD = 1e9 + 7;
  vector<long long> p;
  int n;
  string res = "";
  string longestDupSubstring(string s) {
    n = s.size();

    p.assign(n, 1);
    for (int i = 1; i < n; ++i)
      p[i] = p[i - 1] * 26 % MOD;

    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (valid(s, mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return res;
  }

  bool valid(string &s, int k) {
    unordered_map<long long, vector<int>> umap;

    long long hash = 0;
    for (int i = 0; i < n; ++i) {
      if (i - k >= 0) {
        hash = (hash - (s[i - k] - 'a') * p[k - 1]) % MOD;
        if (hash < 0)
          hash += MOD;
      }
      hash *= 26;
      hash += (s[i] - 'a');
      hash %= MOD;
      if (i >= k - 1) {
        if (umap.count(hash)) {
          string t = s.substr(i - k + 1, k);
          auto &v = umap[hash];
          for (auto j : v)
            if (t == s.substr(j - k + 1, k)) {
              res = t;
              return true;
            }
        }
        umap[hash].push_back(i);
      }
    }

    return false;
  }
};