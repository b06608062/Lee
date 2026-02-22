// mark
// 分析複雜度 + DFS 記憶化搜索 + gcd 最簡分數

class Solution {
public:
  using ll = long long;
  // memo[i][p][q] = count
  vector<unordered_map<ll, unordered_map<ll, ll>>> memo;
  vector<int> a;
  ll K;
  ll countSequences(vector<int> &nums, ll k) {
    a = nums;
    K = k;
    memo.assign(a.size(), {});
    return dfs(a.size() - 1, 1ll, 1ll);
  }

  ll dfs(int i, ll p, ll q) {
    if (i < 0)
      return (p == K && q == 1) ? 1ll : 0ll;

    auto itp = memo[i].find(p);
    if (itp != memo[i].end()) {
      auto itq = itp->second.find(q);
      if (itq != itp->second.end())
        return itq->second;
    }

    ll x = a[i];
    ll res = 0;

    // divide: p / (q*x)
    {
      ll qq = q * x;
      ll g = gcd(p, qq);
      res += dfs(i - 1, p / g, qq / g);
    }

    // multiply: (p*x) / q
    {
      ll pp = p * x;
      ll g = gcd(pp, q);
      res += dfs(i - 1, pp / g, q / g);
    }

    // unchanged
    res += dfs(i - 1, p, q);

    return memo[i][p][q] = res;
  }
};