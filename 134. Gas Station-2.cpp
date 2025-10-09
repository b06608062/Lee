// 存在可行起點 ⇔ ∑(gas[i] − cost[i]) ≥ 0
// 前綴和 & 最小前綴
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();

    vector<int> prefix(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += gas[i] - cost[i];
      prefix[i] = total;
    }

    int res =
        (min_element(prefix.begin(), prefix.end()) - prefix.begin() + 1) % n;

    return total >= 0 ? res : -1;
  }
};