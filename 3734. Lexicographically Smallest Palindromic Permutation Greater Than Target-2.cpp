// mark
// 2330
// Leetcode 3720 變形
// 字串字典序下一排列 + 從中點往左構造合法回文字串
class Solution {
public:
  string lexPalindromicPermutation(string s, string target) {
    int n = s.size();

    int cnt[26];
    for (auto ch : s)
      cnt[ch - 'a']++;

    char midCh = 0;
    for (int i = 0; i < 26; ++i)
      if (cnt[i] % 2 != 0)
        if (midCh)
          return "";
        else {
          midCh = i + 'a';
          cnt[i]--;
        }

    string res = target;
    for (int i = 0; i < n / 2; ++i) {
      char ch = target[i];
      cnt[ch - 'a'] -= 2;
      res[i] = res[n - 1 - i] = ch;
    }

    if (midCh > 0)
      res[n / 2] = midCh;

    auto valid = [&]() -> bool {
      for (auto x : cnt)
        if (x < 0)
          return false;
      return true;
    };

    if (valid() && res > target)
      return res;

    for (int i = n / 2 - 1; i >= 0; --i) {
      int t = target[i] - 'a';
      cnt[t] += 2;
      if (!valid())
        continue;

      for (int j = t + 1; j < 26; ++j) {
        if (cnt[j]) {
          res[i] = res[n - 1 - i] = j + 'a';
          cnt[j] -= 2;
          string right = res.substr(n - 1 - i);
          res.resize(i + 1);
          string mid = "";
          for (int k = 0; k < 26; ++k)
            mid += string(cnt[k] / 2, k + 'a');
          res += mid;
          if (midCh > 0)
            res += midCh;
          reverse(mid.begin(), mid.end());
          res += mid + right;
          return res;
        }
      }
    }

    return "";
  }
};