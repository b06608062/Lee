const int MX = 100001;
int core[MX];

// 平方核預處理（類似篩法）：O(MX * (1 + 1/2^2 + 1/3^2 + ...))，收斂到 O(MX)
auto init = [] {
  // 從 1 到 MX-1 逐一嘗試當作「平方核候選」i
  for (int i = 1; i < MX; ++i)
    // 只處理目前還沒被指派平方核的 i
    // 重要含意：若 core[i] 仍為 0，表示 i 不是任何「較小平方核」k 與某個平方
    // j^2 的乘積，
    //           因而 i 必為「平方自由數」（square-free）。
    if (core[i] == 0)
      // 將所有形如 i * j^2 的數字的平方核都設為 i
      // 也就是：凡是 n = i * j^2，n 的平方核就是 i
      // j 從 1 開始：j=1 時會把 core[i] 設為 i（平方核定義本身）
      for (int j = 1; 1LL * i * j * j < MX;
           ++j) // 用 1LL 防溢位：i*j*j 先提升為 long long 再比較
        core[i * j * j] = i;
  return 0;
}();

class Solution {
public:
  long long sumOfAncestors(int n, vector<vector<int>> &edges,
                           vector<int> &nums) {
    vector adj(n, vector<int>());
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    unordered_map<int, long long> umap;
    long long res = 0;

    auto dfs = [&](this auto &&dfs, int u, int parent) -> void {
      int c = core[nums[u]];
      res += umap[c];
      umap[c]++;
      for (auto v : adj[u])
        if (v != parent)
          dfs(v, u);
      umap[c]--;
    };

    dfs(0, -1);

    return res;
  }
};