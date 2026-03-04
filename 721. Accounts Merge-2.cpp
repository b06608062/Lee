struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int e_id = 0;
    unordered_map<string, int> emails;
    unordered_map<int, string> e2n;
    for (auto &a : accounts) {
      int sz = a.size();
      for (int i = 1; i < sz; ++i) {
        auto &email = a[i];
        if (!emails.count(email)) {
          e2n[e_id] = a[0];
          emails[email] = e_id++;
        }
      }
    }

    DSU dsu(emails.size());
    for (auto &a : accounts) {
      int sz = a.size();
      for (int i = 2; i < sz; ++i)
        dsu.unite(emails[a[1]], emails[a[i]]);
    }

    unordered_map<int, set<string>> groups;
    for (auto &[email, e_id] : emails)
      groups[dsu.find(e_id)].insert(email);

    vector<vector<string>> res;
    for (auto &[root_id, group] : groups) {
      res.push_back({e2n[root_id]});
      for (auto &email : group)
        res.back().push_back(email);
    }
    return res;
  }
};