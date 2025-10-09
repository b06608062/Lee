class Solution {
public:
  string majorityFrequencyGroup(string s) {
    vector<int> freq(26, 0);
    for (auto ch : s)
      freq[ch - 'a']++;

    unordered_map<int, int> umap;
    for (int i = 0; i < 26; ++i)
      if (freq[i])
        umap[freq[i]]++;

    vector<pair<int, int>> arr; // size, freq
    for (auto [k, v] : umap)
      arr.push_back({v, k});

    sort(arr.rbegin(), arr.rend());

    int k = arr[0].second;

    string res = "";
    for (int i = 0; i < 26; ++i)
      if (freq[i] == k)
        res += char(i + 'a');

    return res;
  }
};