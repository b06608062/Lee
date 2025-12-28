// mark
// 1823
// Greedy + 保存候選名單
class Solution {
public:
  long long maximumScore(vector<int> &nums, string s) {
    int n = nums.size();

    // max heap
    priority_queue<int> pq;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      pq.push(nums[i]);
      if (s[i] == '1') {
        res += pq.top();
        pq.pop();
      }
    }

    return res;
  }
};