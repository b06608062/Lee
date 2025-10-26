class Solution {
public:
  long long countStableSubarrays(vector<int> &capacity) {
    int n = capacity.size();

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + capacity[i - 1];

    map<pair<long long, long long>, int> mmap;

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      if (i - 2 >= 0) {
        int l = i - 2;
        mmap[{capacity[l], pref[l + 1]}]++;
      }
      int x = capacity[i];
      res += mmap[{x, pref[i] - x}];
    }

    return res;
  }
};