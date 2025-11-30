class Solution {
public:
  int numberOfSpecialChars(string word) {
    int n = word.size();
    vector<int> cnt1(26, -1), cnt2(26, -1);

    for (int i = 0; i < n; ++i) {
      char ch = word[i];
      if ('a' <= ch && ch <= 'z')
        cnt1[ch - 'a'] = i;
      else if (cnt2[ch - 'A'] == -1)
        cnt2[ch - 'A'] = i;
    }

    int res = 0;
    for (int i = 0; i < 26; ++i)
      if (cnt1[i] != -1 && cnt2[i] != -1 && cnt1[i] < cnt2[i])
        res++;

    return res;
  }
};