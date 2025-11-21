class Solution {
public:
  int countPalindromicSubsequence(string s) {
    int n = s.size();
    vector<int> left(26, n), right(26, -1);
    for (int i = 0; i < n; ++i)
      if (left[s[i] - 'a'] == n)
        left[s[i] - 'a'] = i;
    for (int i = n - 1; i >= 0; --i)
      if (right[s[i] - 'a'] == -1)
        right[s[i] - 'a'] = i;

    bool vis[26][26] = {false};

    for (int i = 1; i < n - 1; ++i)
      for (int j = 0; j < 26; ++j)
        if (left[j] < i && right[j] > i)
          vis[s[i] - 'a'][j] = true;

    int res = 0;
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        if (vis[i][j])
          ++res;

    return res;
  }
};
