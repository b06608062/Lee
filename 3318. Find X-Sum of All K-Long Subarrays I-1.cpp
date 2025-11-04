class Solution {
public:
  vector<int> findXSum(vector<int> &nums, int k, int x) {
    int n = nums.size();

    unordered_map<int, int> umap;

    vector<int> res;
    for (int i = 0; i < n; ++i) {
      umap[nums[i]]++;
      if (i >= k - 1) {
        vector<pair<int, int>> temp;
        for (auto [x, f] : umap)
          temp.push_back({f, x});
        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
          if (a.first != b.first)
            return a.first > b.first;
          return a.second > b.second;
        });

        int curSum = 0, size = min(x, (int)temp.size());
        for (int j = 0; j < size; ++j)
          curSum += temp[j].second * temp[j].first;
        res.push_back(curSum);

        int toRemove = nums[i - (k - 1)];
        if (--umap[toRemove] == 0)
          umap.erase(toRemove);
      }
    }

    return res;
  }
};