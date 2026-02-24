class Solution {
public:
  bool hasAllCodes(string s, int k) {
    int n = s.size();
    if (k > n)
      return false;

    unordered_set<int> uset;
    int cur = 0;
    for (int i = 0; i < k; ++i)
      cur = cur << 1 | (s[i] - '0');
    uset.insert(cur);

    int mask = (1 << k) - 1;
    int r = k;
    while (r < n) {
      cur = (cur << 1 | (s[r++] - '0')) & mask;
      uset.insert(cur);
    }

    return uset.size() == (1 << k);
  }
};