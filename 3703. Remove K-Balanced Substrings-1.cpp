// mark
// 1802
// 括號匹配 + Vector Stack 模擬貪心消除 + 狀態壓縮
class Solution {
public:
  string removeSubstring(string s, int k) {
    vector<pair<char, int>> st;
    for (auto ch : s) {
      if (!st.empty() && st.back().first == ch)
        st.back().second++;
      else
        st.push_back({ch, 1});
      if (ch == ')' && st.size() >= 2 && st.back().second == k) {
        if (st[st.size() - 2].second >= k) {
          st.pop_back();
          st.back().second -= k;
          if (st.back().second == 0)
            st.pop_back();
        }
      }
    }

    string res = "";
    for (auto [ch, cnt] : st)
      res += string(cnt, ch);

    return res;
  }
};