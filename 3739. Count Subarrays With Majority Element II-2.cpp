// mark
// 2090
// 有序統計樹 Ordered Set (PBDS) + 差分前綴和
// 利用 order_of_key 統計前綴和 < cur 的個數
// 在一棵平衡 BST（像 AVL / Red-Black
// Tree）上，額外維護每個節點的子樹大小，然後用這個來做 order_of_key /
// find_by_order 操作
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    ordered_set oset;

    int idx = 0;
    oset.insert({0, ++idx});

    long long res = 0;
    int cur = 0;
    for (auto x : nums) {
      cur += x == target ? 1 : -1;
      res += oset.order_of_key({cur, 0});
      oset.insert({cur, ++idx});
    }

    return res;
  }
};
