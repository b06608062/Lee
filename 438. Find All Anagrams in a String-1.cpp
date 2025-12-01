class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int m = s.size(), n = p.size();
    vector<int> res;
    if (n > m)
      return res;

    vector<int> freqS(26, 0), freqP(26, 0);
    for (int i = 0; i < n; ++i) {
      freqS[s[i] - 'a']++;
      freqP[p[i] - 'a']++;
    }

    int same = 0;
    for (int i = 0; i < 26; ++i)
      if (freqS[i] == freqP[i])
        same++;

    if (same == 26)
      res.push_back(0);

    int l = 0, r = n - 1;
    while (r + 1 < m) {
      int toDel = s[l++] - 'a';
      if (freqS[toDel] == freqP[toDel])
        same--;
      freqS[toDel]--;
      if (freqS[toDel] == freqP[toDel])
        same++;

      int toAdd = s[++r] - 'a';
      if (freqS[toAdd] == freqP[toAdd])
        same--;
      freqS[toAdd]++;
      if (freqS[toAdd] == freqP[toAdd])
        same++;

      if (same == 26)
        res.push_back(l);
    }

    return res;
  }
};