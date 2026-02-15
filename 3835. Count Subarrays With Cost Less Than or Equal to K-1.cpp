// mark
// 1759
// Sliding Window + mn/mx deque

class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    long long res = 0;
    int l = 0;
    deque<int> dq_mn, dq_mx;
    for (int r = 0; r < n; ++r) {
      int x = nums[r];
      while (!dq_mn.empty() && x <= nums[dq_mn.back()]) {
        dq_mn.pop_back();
      }
      dq_mn.push_back(r);
      while (!dq_mx.empty() && x >= nums[dq_mx.back()]) {
        dq_mx.pop_back();
      }
      dq_mx.push_back(r);
      while (l < r &&
             1ll * (nums[dq_mx.front()] - nums[dq_mn.front()]) * (r - l + 1) >
                 k) {
        l++;
        if (dq_mn.front() < l) {
          dq_mn.pop_front();
        }
        if (dq_mx.front() < l) {
          dq_mx.pop_front();
        }
      }
      res += (r - l + 1);
    }

    return res;
  }
};

// TLE
class Solution {
public:
  vector<pair<int, int>> tree; // min, max
  void build(int p, int l, int r, vector<int> &nums) {
    if (l == r) {
      tree[p] = {nums[l], nums[l]};
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m, nums);
    build(p << 1 | 1, m + 1, r, nums);
    pull(p);
  }

  void pull(int p) {
    tree[p].first = min(tree[p << 1].first, tree[p << 1 | 1].first);    // min
    tree[p].second = max(tree[p << 1].second, tree[p << 1 | 1].second); // max
  }

  pair<int, int> query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
      return {INT_MAX, INT_MIN};
    }
    if (ql <= l && r <= qr) {
      return tree[p];
    }
    int m = (l + r) / 2;
    auto L = query(p << 1, l, m, ql, qr);
    auto R = query(p << 1 | 1, m + 1, r, ql, qr);
    return {min(L.first, R.first), max(L.second, R.second)};
  }

  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    tree.resize(4 * n);
    build(1, 0, n - 1, nums);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int l = 0, r = i + 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        auto [mn, mx] = query(1, 0, n - 1, m, i);
        if (1ll * (mx - mn) * (i - m + 1) > k) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      res += (i - l + 1);
    }

    return res;
  }
};