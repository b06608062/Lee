class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    unordered_map<char, vector<int>> pos;
    for (int i = 0; i < m; ++i)
      pos[text1[i]].push_back(i);
    for (auto &[k, v] : pos)
      reverse(v.begin(), v.end());
    vector<int> v;
    for (char &ch : text2) {
      if (pos.count(ch))
        for (auto idx : pos[ch])
          v.push_back(idx);
    }

    vector<int> tails;
    for (auto x : v) {
      int i = lower_bound(tails.begin(), tails.end(), x) - tails.begin();
      if (i == tails.size())
        tails.push_back(x);
      else
        tails[i] = x;
    }

    return tails.size();
  }
};
