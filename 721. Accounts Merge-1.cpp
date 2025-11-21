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
    int n = accounts.size();

    unordered_map<string, vector<int>> umap; // mail, idxs
    for (int i = 0; i < n; ++i) {
      auto &acc = accounts[i];
      for (int j = 1; j < acc.size(); ++j)
        umap[acc[j]].push_back(i);
    }

    DSU dsu(n);
    for (auto &[_, idxs] : umap) {
      for (int i = 0; i < idxs.size(); ++i)
        dsu.unite(idxs[0], idxs[i]);
    }

    unordered_map<int, set<string>> groups;
    for (auto &[mail, idxs] : umap)
      groups[dsu.find(idxs[0])].insert(mail);

    vector<vector<string>> res;
    for (auto &[idx, mails] : groups) {
      res.push_back({accounts[idx][0]});
      for (auto &mail : mails)
        res.back().push_back(mail);
    }

    return res;
  }
};

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
    p[b] = a, sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
      auto &acci = accounts[i];
      unordered_set<string> maili(acci.begin() + 1, acci.end());
      for (int j = i + 1; j < n; ++j) {
        auto &accj = accounts[j];
        if (acci[0] == accj[0]) {
          int sz = accj.size();
          for (int k = 1; k < sz; ++k)
            if (maili.count(accj[k])) {
              dsu.unite(i, j);
              break;
            }
        }
      }
    }

    unordered_map<int, set<string>> groups;
    for (int i = 0; i < n; ++i) {
      int rooti = dsu.find(i);
      auto &acci = accounts[i];
      int sz = acci.size();
      for (int k = 1; k < sz; ++k)
        groups[rooti].insert(acci[k]);
    }

    vector<vector<string>> res;
    for (auto &[k, v] : groups) {
      res.push_back({accounts[k][0]});
      res.back().insert(res.back().end(), v.begin(), v.end());
    }

    return res;
  }
};
