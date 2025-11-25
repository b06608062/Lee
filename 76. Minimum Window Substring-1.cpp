class Solution {
public:
  string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    if (n > m)
      return "";

    vector<int> freqT(128, 0);
    for (char c : t)
      freqT[c]++;

    int required = 0;
    for (int i = 0; i < 128; ++i)
      if (freqT[i] > 0)
        required++;

    vector<int> windowFreq(128, 0);

    int left = 0, right = 0, formed = 0, minLen = INT_MAX, start = 0;
    while (right < m) {
      char c = s[right];
      if (++windowFreq[c] == freqT[c])
        formed++;

      while (formed == required) {
        int windowSize = right - left + 1;
        if (windowSize < minLen) {
          minLen = windowSize;
          start = left;
        }

        char lc = s[left++];
        if (--windowFreq[lc] < freqT[lc])
          formed--;
      }

      right++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
  }
};