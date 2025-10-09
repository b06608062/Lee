class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> uset;

    int i = 0, res = 0;
    for (int j = 0; j < s.size(); ++j)
      if (!uset.count(s[j])) {
        uset.insert(s[j]);
        res = max(res, (int)uset.size());
      } else {
        while (i < j && s[i] != s[j]) {
          uset.erase(s[i]);
          i++;
        }
        i++;
      }

    return res;
  }
};