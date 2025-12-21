class Solution {
public:
  vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
    int n = nums.size();

    set<pair<long long, int>> sset;
    unordered_map<int, long long> umap;
    vector<long long> res;

    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (umap.count(x))
        sset.erase({umap[x], x});
      umap[x] += freq[i];
      sset.insert({umap[x], x});
      res.push_back((*sset.rbegin()).first);
    }

    return res;
  }
};