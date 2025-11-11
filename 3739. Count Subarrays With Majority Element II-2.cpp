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
