class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    unordered_set<int> uset;
    for (auto x : nums) {
      if (uset.count(x))
        return x;
      uset.insert(x);
    }

    return -1;
  }
};