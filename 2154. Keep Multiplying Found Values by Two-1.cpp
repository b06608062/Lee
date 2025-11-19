class Solution {
public:
  int findFinalValue(vector<int> &nums, int original) {
    unordered_set<int> uset;
    for (auto x : nums)
      uset.insert(x);

    while (uset.count(original))
      original *= 2;

    return original;
  }
};