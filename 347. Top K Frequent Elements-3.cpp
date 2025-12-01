// Follow up: Your algorithm's time complexity must be better than O(n log n),
// where n is the array's size.
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> freq;
    for (int x : nums)
      freq[x]++;

    vector<vector<int>> bucket(n + 1);
    for (auto [x, f] : freq)
      bucket[f].push_back(x);

    vector<int> res;

    int cnt = 0;
    for (int i = n; i >= 1 && cnt < k; --i) {
      for (auto x : bucket[i]) {
        res.push_back(x);
        if (++cnt == k)
          break;
      }
    }

    return res;
  }
};
