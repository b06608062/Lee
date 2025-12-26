// mark
// 線段數進階桶狀樹 + BFS
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Problem model (assumed):
- Floors: 1..n
- m elevators; elevator i covers [L[i], R[i]].
  If you are at any floor f in [L[i], R[i]], you may take elevator i and go to
floor R[i].
- Cost of taking an elevator = 1 (we minimize number of elevator rides).
- Walking inside the same floor is free and irrelevant in this abstract model.
Goal: minimum rides from floor 1 to floor n. Output -1 if impossible.
*/

struct SegTreeBuckets {
  int n;
  vector<vector<int>> bucket;

  SegTreeBuckets(int n = 0) { init(n); }

  void init(int n_) {
    n = n_;
    bucket.assign(4 * n, {});
  }

  void add_interval(int ql, int qr, int id) {
    add_interval(1, 1, n, ql, qr, id);
  }

  // Collect all ids that cover point x, and CLEAR buckets along the path.
  void query_point_and_clear(int x, vector<int> &out) {
    query_point_and_clear(1, 1, n, x, out);
  }

private:
  void add_interval(int node, int L, int R, int ql, int qr, int id) {
    if (qr < L || R < ql)
      return;
    if (ql <= L && R <= qr) {
      bucket[node].push_back(id);
      return;
    }
    int mid = (L + R) >> 1;
    add_interval(node << 1, L, mid, ql, qr, id);
    add_interval(node << 1 | 1, mid + 1, R, ql, qr, id);
  }

  void query_point_and_clear(int node, int L, int R, int x, vector<int> &out) {
    if (!bucket[node].empty()) {
      out.insert(out.end(), bucket[node].begin(), bucket[node].end());
      bucket[node]
          .clear(); // critical: each elevator processed at most once overall
    }
    if (L == R)
      return;
    int mid = (L + R) >> 1;
    if (x <= mid)
      query_point_and_clear(node << 1, L, mid, x, out);
    else
      query_point_and_clear(node << 1 | 1, mid + 1, R, x, out);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> L(m), R(m);
  for (int i = 0; i < m; i++) {
    cin >> L[i] >> R[i];
    if (L[i] > R[i])
      swap(L[i], R[i]); // safety
    L[i] = max(L[i], 1);
    R[i] = min(R[i], n);
  }

  SegTreeBuckets st(n);
  for (int i = 0; i < m; i++) {
    st.add_interval(L[i], R[i], i);
  }

  const int INF = 1e9;
  vector<int> dist(n + 1, INF);
  queue<int> q;

  dist[1] = 0;
  q.push(1);

  while (!q.empty()) {
    int f = q.front();
    q.pop();
    if (f == n)
      break;

    vector<int> ids;
    st.query_point_and_clear(f, ids);

    for (int id : ids) {
      int to = R[id]; // exit at upper endpoint
      if (dist[to] == INF) {
        dist[to] = dist[f] + 1;
        q.push(to);
      }
    }
  }

  cout << (dist[n] == INF ? -1 : dist[n]) << "\n";
  return 0;
}

// clang++ -std=c++17 -O2 -Wall -Wextra -pedantic elevator.cpp -o test

/*
./test << 'EOF'
10 4
1 4
3 7
4 10
6 10
EOF
*/

/*
./test << 'EOF'
8 1
1 8
EOF
*/

/*
./test << 'EOF'
8 2
2 5
6 8
EOF
*/

/*
./test << 'EOF'
10 4
4 1
7 4
10 7
10 10
EOF
*/