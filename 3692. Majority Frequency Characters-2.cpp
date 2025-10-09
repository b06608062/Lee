class Solution {
public:
  string majorityFrequencyGroup(string s) {
    vector<int> freq(26, 0);
    for (auto ch : s)
      freq[ch - 'a']++;

    unordered_map<int, int> umap; // f, size
    for (int i = 0; i < 26; ++i)
      if (freq[i])
        umap[freq[i]]++;

    int bestF = 0, bestSize = 0;
    for (auto [f, size] : umap)
      if (size > bestSize || (size == bestSize && f > bestF))
        bestF = f, bestSize = size;

    string res = "";
    for (int i = 0; i < 26; ++i)
      if (freq[i] == bestF)
        res += char(i + 'a');

    return res;
  }
};