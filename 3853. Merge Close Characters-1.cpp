class Solution {
public:
  string mergeCharacters(string s, int k) {
    int n = s.size();
    vector<int> left(26, -1);

    string res = "";
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int c = s[i] - 'a';
      if (left[c] == -1) {
        left[c] = i - cnt;
        res += s[i];
      } else {
        if ((i - cnt) - left[c] <= k)
          cnt++;
        else {
          left[c] = i - cnt;
          res += s[i];
        }
      }
    }
    return res;
  }
};