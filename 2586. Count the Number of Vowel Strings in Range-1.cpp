class Solution {
public:
  int vowelStrings(vector<string> &words, int left, int right) {
    unordered_set<char> uset{'a', 'e', 'i', 'o', 'u'};

    int res = 0;
    for (int i = left; i <= right; ++i) {
      string &w = words[i];
      if (uset.count(w[0]) && uset.count(w[w.size() - 1]))
        res++;
    }

    return res;
  }
};