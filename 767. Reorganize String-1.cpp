class Solution {
public:
  string reorganizeString(string s) {
    int freq[26];
    for (auto ch : s)
      freq[ch - 'a']++;

    // max heap
    using P = pair<int, int>; // f, ch
    priority_queue<P> pq;

    for (int i = 0; i < 26; ++i)
      if (freq[i] > 0)
        pq.push({freq[i], i + 'a'});

    string res = "";
    while (!pq.empty()) {
      int k = 2;
      vector<P> temp;
      while (k > 0 && !pq.empty()) {
        auto [f, ch] = pq.top();
        pq.pop();
        res += ch;
        if (--f)
          temp.push_back({f, ch});
        k--;
      }

      for (auto [f, ch] : temp)
        pq.push({f, ch});

      if (k > 0 && !pq.empty())
        return "";
    }

    return res;
  }
};