class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    vector<vector<int>> prefix(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1];
      prefix[i][s[i - 1] - 'A']++;
    }

    auto helper = [&](int L) {
      int best = 0;
      for (int i = L; i <= n; ++i)
        for (int j = 0; j < 26; ++j)
          best = max(best, prefix[i][j] - prefix[i - L][j]);
      return best + k >= L;
    };

    int lo = 1, hi = n + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (helper(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo - 1;
  }
};