class Solution {
public:
  int minDeletions(string s) {
    unordered_map<char, int> umap;
    for (auto ch : s)
      umap[ch]++;

    vector<int> freq;
    for (auto [k, f] : umap)
      freq.push_back(f);

    int n = freq.size();

    sort(freq.begin(), freq.end(), greater<int>());

    int res = 0, max_allowed = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int f = freq[i];
      if (max_allowed == 0) {
        res += f;
      } else if (f > max_allowed) {
        res += f - max_allowed;
        max_allowed--;
      } else
        max_allowed = f - 1;
    }

    return res;
  }
};