class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    map<int, vector<vector<int>>> mmap;
    for (int i = 0; i < n - 1; ++i) {
      int a = arr[i], b = arr[i + 1];
      mmap[b - a].push_back({a, b});
    }

    return (*mmap.begin()).second;
  }
};