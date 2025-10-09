class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int minLen = INT_MAX;
    for (auto &s : strs)
      minLen = min(minLen, (int)s.size());

    string res = "";
    for (int i = 0; i < minLen; ++i) {
      char c = strs[0][i];
      for (auto &s : strs)
        if (s[i] != c)
          return res;
      res += c;
    }

    return res;
  }
};