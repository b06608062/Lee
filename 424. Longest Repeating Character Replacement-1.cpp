class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    int freq[26] = {0};

    int maxFreq = 0;
    int i = 0;
    for (int j = 0; j < n; ++j) {
      maxFreq = max(maxFreq, ++freq[s[j] - 'A']);
      if (maxFreq + k < j - i + 1)
        freq[s[i++] - 'A']--;
    }

    return min(maxFreq + k, n);
  }
};