// mark
// 有序統計樹 Ordered Set (PBDS) + 二分搜尋
// 利用 order_of_key 統計區間內相同字元的個數
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
  vector<int> minDeletions(string s, vector<vector<int>> &queries) {
    int n = s.size();
    ordered_set oset;

    for (int i = 1; i < n; ++i)
      if (s[i] == s[i - 1])
        oset.insert(i);

    vector<int> res;
    for (auto &q : queries) {
      if (q[0] == 1) {
        int j = q[1];
        oset.erase(j);
        oset.erase(j + 1);
        s[j] ^= 'A' ^ 'B';
        if (j - 1 >= 0 && s[j] == s[j - 1])
          oset.insert(j);
        if (j + 1 < n && s[j] == s[j + 1])
          oset.insert(j + 1);
      } else {
        // [l + 1, r]
        int l = q[1], r = q[2];
        int L = l + 1, R = r;
        int cnt = oset.order_of_key(R + 1) - oset.order_of_key(L);
        res.push_back(cnt);
      }
    }

    return res;
  }
};