class Solution {
public:
  vector<string> commonChars(vector<string> &words) {
    int cnt[26];
    for (int i = 0; i < 26; ++i)
      cnt[i] = INT_MAX;

    for (auto &w : words) {
      int temp[26];
      for (auto ch : w)
        temp[ch - 'a']++;
      for (int i = 0; i < 26; ++i)
        cnt[i] = min(cnt[i], temp[i]);
    }

    vector<string> res;
    for (int i = 0; i < 26; ++i) {
      int n = cnt[i];
      while (n--)
        res.push_back(string(1, i + 'a'));
    }

    return res;
  }
};