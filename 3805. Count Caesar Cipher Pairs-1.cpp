class Solution {
public:
  long long countPairs(vector<string> &words) {
    int m = words[0].size();

    map<vector<int>, int> mmap;

    long long res = 0;
    for (auto &word : words) {
      vector<int> key;
      for (int i = 1; i < m; ++i) {
        key.push_back((word[i] - word[i - 1] + 26) % 26);
      }
      res += mmap[key]++;
    }

    return res;
  }
};