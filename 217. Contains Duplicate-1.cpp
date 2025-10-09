class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> umap;
    for (int x : nums) {
      if (umap.count(x))
        return true;
      umap.insert(x);
    }

    return false;
  }
};