class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string res = "";
    for (auto &w : words) {
      int cur = 0;
      for (auto ch : w)
        cur += weights[ch - 'a'];
      res += (25 - cur % 26) + 'a';
    }
    return res;
  }
};