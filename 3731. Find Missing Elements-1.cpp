class Solution {
public:
  vector<int> findMissingElements(vector<int> &nums) {
    unordered_set<int> uset;
    for (auto x : nums)
      uset.insert(x);

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> res;
    for (int i = minVal; i <= maxVal; ++i)
      if (!uset.count(i))
        res.push_back(i);

    return res;
  }
};