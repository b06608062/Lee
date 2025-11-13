class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();

    using P = pair<int, int>;
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<bool> vis(n, false);
    pq.push({height[0], 0});
    pq.push({height[n - 1], n - 1});
    vis[0] = vis[n - 1] = true;

    int cur = 0, res = 0;
    while (!pq.empty()) {
      auto [h, idx] = pq.top();
      pq.pop();
      res += max(0, cur - h);
      cur = max(cur, h);
      if (idx > 0 && !vis[idx - 1]) {
        vis[idx - 1] = true;
        pq.push({height[idx - 1], idx - 1});
      }

      if (idx < n - 1 && !vis[idx + 1]) {
        vis[idx + 1] = true;
        pq.push({height[idx + 1], idx + 1});
      }
    }

    return res;
  }
};