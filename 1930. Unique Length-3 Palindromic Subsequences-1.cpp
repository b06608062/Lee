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

    unordered_set<string> uset;
    for (int i = 1; i < n - 1; ++i)
      for (int j = 0; j < 26; ++j)
        if (left[j] < i && right[j] > i)
          uset.insert(string(1, j + 'a') + string(1, s[i]) +
                      string(1, j + 'a'));

    return uset.size();
  }
};