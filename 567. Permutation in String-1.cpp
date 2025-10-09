class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2)
      return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (int i = 0; i < n1; ++i) {
      freq1[s1[i] - 'a']++;
      freq2[s2[i] - 'a']++;
    }

    int same = 0;
    for (int i = 0; i < 26; ++i)
      if (freq1[i] == freq2[i])
        same++;
    if (same == 26)
      return true;

    int l = 0, r = n1 - 1;
    while (r + 1 < n2) {
      char toAdd = s2[++r] - 'a';
      char toDelete = s2[l++] - 'a';

      if (freq2[toDelete] == freq1[toDelete])
        same--;
      freq2[toDelete]--;
      if (freq2[toDelete] == freq1[toDelete])
        same++;

      if (freq2[toAdd] == freq1[toAdd])
        same--;
      freq2[toAdd]++;
      if (freq2[toAdd] == freq1[toAdd])
        same++;

      if (same == 26)
        return true;
    }

    return false;
  }
};