class Solution {
public:
  int numberOfSpecialChars(string word) {
    vector<bool> cnt1(26, false), cnt2(26, false);
    for (auto ch : word) {
      if ('a' <= ch && ch <= 'z')
        cnt1[ch - 'a'] = true;
      else
        cnt2[ch - 'A'] = true;
    }

    int res = 0;
    for (int i = 0; i < 26; ++i)
      if (cnt1[i] && cnt2[i])
        res++;

    return res;
  }
};