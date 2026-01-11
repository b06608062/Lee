class Solution {
public:
  int residuePrefixes(string s) {
    int n = s.size();

    unordered_set<char> uset;

    int res = 0;
    for (int i = 0; i < n; ++i) {
      uset.insert(s[i]);
      if (uset.size() > 2)
        break;
      if (uset.size() == (i + 1) % 3)
        res++;
    }

    return res;
  }
};