class Solution {
public:
  string lexGreaterPermutation(string s, string target) {
    int n = s.size();

    int cnt[26] = {0};
    for (auto ch : s)
      cnt[ch - 'a']++;

    string res = "";
    for (auto ch : target) {
      int x = ch - 'a';
      if (cnt[x]) {
        res += ch;
        cnt[x]--;
      } else {
        bool find = false;
        for (int i = x + 1; i < 26; ++i)
          if (cnt[i]) {
            find = true;
            res += char(i + 'a');
            cnt[i]--;
            break;
          }
        if (!find) {
          while (res.size()) {
            int y = res.back() - 'a';
            res.pop_back();
            cnt[y]++;
            find = false;
            for (int i = y + 1; i < 26; ++i)
              if (cnt[i]) {
                find = true;
                res += char(i + 'a');
                cnt[i]--;
                break;
              }
            if (find)
              break;
          }
          if (res.size() == 0)
            return "";
        }
        break;
      }
    }

    string remain = "";
    for (int i = 0; i < 26; ++i)
      if (cnt[i])
        remain += string(cnt[i], char(i + 'a'));
    res += remain;

    return res == target ? (next_permutation(res.begin(), res.end()) ? res : "")
                         : res;
  }
};