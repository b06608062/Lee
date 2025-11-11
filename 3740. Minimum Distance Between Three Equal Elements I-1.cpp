class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, vector<int>> umap;

    for (int i = 0; i < n; ++i)
      umap[nums[i]].push_back(i);

    vector<int> arr;
    for (auto &[_, v] : umap)
      if (v.size() >= 3) {
        int sz = v.size();
        for (int l = 2; l < sz; ++l) {
          int i = v[l - 2], j = v[l - 1], k = v[l];
          arr.push_back(abs(i - j) + abs(j - k) + abs(k - i));
        }
      }

    sort(arr.begin(), arr.end());

    if (arr.empty())
      return -1;

    return arr[0];
  }
};