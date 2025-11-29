class Solution {
public:
  string reorganizeString(string s) {
    int cnt[26];
    for (int i = 0; i < 26; ++i)
      cnt[i] = 0;
    for (auto ch : s)
      cnt[ch - 'a']++;

    using P = pair<int, char>;
    // max heap
    priority_queue<P> pq;

    for (int i = 0; i < 26; ++i)
      if (cnt[i])
        pq.push({cnt[i], i + 'a'});

    string res = "";
    while (!pq.empty()) {
      if (pq.size() == 1) {
        auto [f, ch] = pq.top();
        pq.pop();
        if (f > 1)
          return "";
        else
          return res + ch;
      }

      auto [f_a, ch_a] = pq.top();
      pq.pop();
      res += ch_a;
      auto [f_b, ch_b] = pq.top();
      pq.pop();
      res += ch_b;
      if (--f_a)
        pq.push({f_a, ch_a});
      if (--f_b)
        pq.push({f_b, ch_b});
    }

    return res;
  }
};