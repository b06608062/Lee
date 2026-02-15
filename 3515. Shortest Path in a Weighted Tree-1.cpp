// mark
// 2312
// DFS 時間戳 + 差分樹狀樹組
// 區間更新換成兩點更新
// 單點查詢換成前綴和

struct FenwickTree {
  vector<int> bit;
  FenwickTree(int n) : bit(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < bit.size()) {
      bit[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += bit[i];
      i -= lowbit(i);
    }
    return sum;
  }

  int lowbit(int x) { return x & (-x); }
};

class Solution {
public:
  vector<vector<int>> g;
  vector<int> in, out;
  int clock = 0;
  vector<int> treeQueries(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    g.resize(n + 1);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }

    in.resize(n + 1), out.resize(n + 1);
    dfs(1, 0);

    vector<int> weight(n + 1);
    FenwickTree ft(n);
    auto update = [&](int u, int v, int w) {
      // 每個子節點父節點唯一，邊權記在子節點
      if (in[u] > in[v])
        v = u;
      int d = w - weight[v];
      weight[v] = w;
      ft.update(in[v], d);
      ft.update(out[v] + 1, -d);
    };

    for (auto &e : edges)
      update(e[0], e[1], e[2]);

    vector<int> res;
    for (auto &q : queries)
      if (q[0] == 1)
        update(q[1], q[2], q[3]);
      else
        res.push_back(ft.query(in[q[1]]));

    return res;
  }

  void dfs(int u, int p) {
    in[u] = ++clock;
    for (int v : g[u])
      if (v != p)
        dfs(v, u);
    out[u] = clock;
  };
};