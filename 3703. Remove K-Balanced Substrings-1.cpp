class Solution {
public:
  string removeSubstring(string s, int k) {
    vector<pair<char, int>> st;

    for (char ch : s) {
      if (!st.empty() && st.back().first == ch)
        st.back().second++;
      else
        st.push_back({ch, 1});

      if (st.size() >= 2) {
        auto &r2 = st.back();
        auto &r1 = st[st.size() - 2];
        if (r1.first == '(' && r2.first == ')' && r1.second >= k &&
            r2.second == k) {
          st.pop_back();
          r1.second -= k;
          if (r1.second == 0)
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
