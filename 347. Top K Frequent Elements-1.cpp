class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;

    vector<pair<int, int>> freq;
    for (auto [x, f] : umap)
      freq.push_back({f, x});

    sort(freq.begin(), freq.end(), greater<pair<int, int>>());

    vector<int> res;
    for (int i = 0; i < k; ++i)
      res.push_back(freq[i].second);

    return res;
  }
};