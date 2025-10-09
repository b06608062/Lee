class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> sCount, tCount;

    for (int i = 0; i < s.size(); ++i) {
      sCount[s[i]]++;
      tCount[t[i]]++;
    }

    return sCount == tCount;
  }
};