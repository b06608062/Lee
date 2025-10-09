class Solution {
public:
  int similarPairs(vector<string> &words) {
    int n = words.size();

    vector<vector<bool>> count(n, vector<bool>(26, false));

    for (int i = 0; i < n; ++i) {
      string &word = words[i];
      for (int j = 0; j < word.size(); ++j)
        count[i][word[j] - 'a'] = true;
    }

    int res = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (count[i] == count[j])
          res++;

    return res;
  }
};