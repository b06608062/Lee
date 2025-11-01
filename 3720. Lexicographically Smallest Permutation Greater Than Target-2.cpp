class Solution {
public:
  string lexGreaterPermutation(string s, string target) {
    int n = s.size();

    int cnt[26];
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
      cnt[target[i] - 'a']--;
    }

    bool ok = false;
    for (int i = n - 1; i >= 0; --i) {
      int x = target[i] - 'a';
      cnt[x]++;
      if (!ok) {
        bool check = true;
        for (auto c : cnt)
          if (c < 0) {
            check = false;
            break;
          }
        if (!check)
          continue;
        else
          ok = true;
      }
      for (int j = x + 1; j < 26; ++j) {
        if (cnt[j] > 0) {
          cnt[j]--;
          target[i] = j + 'a';
          target.resize(i + 1);
          for (int k = 0; k < 26; ++k)
            target += string(cnt[k], k + 'a');
          return target;
        }
      }
    }

    return "";
  }
};