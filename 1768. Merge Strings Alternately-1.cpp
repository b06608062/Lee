class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();

    string res;
    int n = min(n1, n2);
    for (int i = 0; i < n; ++i) {
      res.push_back(word1[i]);
      res.push_back(word2[i]);
    }

    if (n1 > n2)
      res += word1.substr(n);
    else
      res += word2.substr(n);

    return res;
  }
};