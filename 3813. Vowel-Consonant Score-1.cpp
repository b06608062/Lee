class Solution {
public:
  int vowelConsonantScore(string s) {
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
    int v = 0, c = 0;
    for (auto ch : s) {
      if (uset.count(ch))
        v++;
      else if (ch - 'a' >= 0 && ch - 'a' < 26)
        c++;
    }
    return c > 0 ? v / c : 0;
  }
};