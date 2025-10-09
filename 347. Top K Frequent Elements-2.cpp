class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    for (int x : nums)
      umap[x]++;

    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (auto [x, f] : umap) {
      pq.push({f, x});
      if (pq.size() > k)
        pq.pop();
    }

    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }
};