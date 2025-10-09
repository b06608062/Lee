struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
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
    unordered_map<string, int> id;       // email -> id
    unordered_map<string, string> owner; // email -> name
    int idx = 0;
    for (auto &acc : accounts) {
      for (int i = 1; i < acc.size(); ++i) {
        string &mail = acc[i];
        if (!id.count(mail)) {
          id[mail] = idx++;
          owner[mail] = acc[0];
        }
      }
    }

    DSU dsu(idx);
    for (auto &acc : accounts) {
      if (acc.size() <= 2)
        continue;
      for (int i = 2; i < acc.size(); ++i)
        dsu.unite(id[acc[1]], id[acc[i]]);
    }

    unordered_map<int, set<string>> groups; // root -> emails
    for (auto &[mail, i] : id)
      groups[dsu.find(i)].insert(mail);

    vector<vector<string>> res;
    for (auto &[_, mails] : groups) {
      res.push_back({owner[*mails.begin()]});
      for (auto &mail : mails)
        res.back().push_back(mail);
    }

    return res;
  }
};
