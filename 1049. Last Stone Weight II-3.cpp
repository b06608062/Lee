class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    unordered_set<int> uset({0}), temp;

    for (auto x : stones) {
      temp = uset;
      for (auto i : temp) {
        uset.insert(i + x);
      }
    }

    int A = 0;
    for (auto x : uset)
      if (x <= sum / 2)
        A = max(A, x);

    // B - A
    return sum - 2 * A;
  }
};