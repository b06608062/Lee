class Solution {
public:
  string oddString(vector<string> &words) {
    map<vector<int>, vector<string>> mmap;
    int n = words[0].size();
    for (auto &w : words) {
      vector<int> arr(n - 1);
      for (int i = 0; i < n - 1; ++i)
        arr[i] = w[i + 1] - w[i];
      mmap[arr].push_back(w);
    }

    for (auto &[k, v] : mmap)
      if (v.size() == 1)
        return v[0];

    return "";
  }
};