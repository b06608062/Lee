class Solution {
public:
  string trimTrailingVowels(string s) {
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};
    int n = s.size();
    int j = n - 1;
    for (; j >= 0; --j)
      if (!uset.count(s[j]))
        break;
    return s.substr(0, j + 1);
  }
};