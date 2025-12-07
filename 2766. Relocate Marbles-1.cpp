class Solution {
public:
  vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom,
                              vector<int> &moveTo) {
    unordered_set<int> uset;
    for (auto x : nums)
      uset.insert(x);
    int n = moveFrom.size();
    for (int i = 0; i < n; ++i) {
      int from = moveFrom[i], to = moveTo[i];
      if (uset.count(from)) {
        uset.erase(from);
        uset.insert(to);
      }
    }

    vector<int> res(uset.begin(), uset.end());
    sort(res.begin(), res.end());
    return res;
  }
};