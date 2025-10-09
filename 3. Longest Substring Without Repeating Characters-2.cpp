class Solution {
public:
  int lengthOfLongestSubstring(const string &s) {
    vector<int> lastIndex(256, -1);

    int i = 0, res = 0;
    for (int j = 0; j < s.size(); ++j) {
      char c = s[j];
      if (lastIndex[c] >= i)
        i = lastIndex[c] + 1;
      lastIndex[c] = j;
      res = max(res, j - i + 1);
    }

    return res;
  }
};