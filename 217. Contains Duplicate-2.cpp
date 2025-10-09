class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> uset;
    uset.reserve(nums.size());
    for (int x : nums)
      if (!uset.insert(x).second) // insert 回傳 {iterator, bool}
        return true;

    return false;
  }
};