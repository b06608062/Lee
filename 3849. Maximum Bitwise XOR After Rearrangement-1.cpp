class Solution {
public:
  string maximumXor(string s, string t) {
    int n = s.size();

    int cnt0 = 0, cnt1 = 0;
    for (auto &ch : t)
      ch == '0' ? cnt0++ : cnt1++;

    string res = s;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0' && cnt1) {
        res[i] = '1';
        cnt1--;
      } else if (s[i] == '1' && cnt0) {
        res[i] = '1';
        cnt0--;
      } else {
        res[i] = (s[i] - '0') ^ (cnt0 ? 0 : 1) + '0';
        cnt0 ? cnt0-- : cnt1--;
      }
    }

    return res;
  }
};