class Solution {
public:
  string minWindow(string s, string t) {
    int n1 = s.size(), n2 = t.size();
    if (n2 > n1)
      return "";
    vector<int> cnt1(128, 0), cnt2(128, 0);
    int target = 0;
    for (auto &ch : t) {
      if (cnt2[ch] == 0)
        ++target;
      ++cnt2[ch];
    }
    int l = 0, cur = 0, start = -1, len = n1 + 1;
    for (int r = 0; r < n1; ++r) {
      char to_add = s[r];
      if (++cnt1[to_add] == cnt2[to_add])
        ++cur;
      while (cur == target) {
        if (r - l + 1 < len) {
          start = l;
          len = r - l + 1;
        }
        char to_del = s[l++];
        if (--cnt1[to_del] < cnt2[to_del])
          cur--;
      }
    }
    return len == n1 + 1 ? "" : s.substr(start, len);
  }
};
