class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0)
      return;
    int count = 0;
    for (int start = 0; count < n; ++start) {
      int cur = start;
      int x = nums[cur];
      do {
        count++;
        int nxt = (cur + k) % n;
        int temp = nums[nxt];
        nums[nxt] = x;
        x = temp;
        cur = nxt;
      } while (cur != start);
    }
  }
};