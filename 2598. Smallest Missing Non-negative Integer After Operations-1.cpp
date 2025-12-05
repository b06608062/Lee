class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    unordered_map<int, int> umap;

    for (auto x : nums)
      umap[(x % value + value) % value]++;

    int minFreq = nums.size(), minNum = -1;
    for (int i = 0; i < value; ++i)
      if (!umap.count(i))
        return i;
      else {
        if (minNum == -1 || umap[i] < minFreq) {
          minFreq = umap[i];
          minNum = i;
        }
      }

    return minNum + minFreq * value;
  }
};