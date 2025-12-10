// mark
// 2235
// 樹狀前綴狀態 + 哈希表計數 + 平方核預處理
const int MX = 100001;
int core[MX];

// 平方自由數定義：一個正整數如果不能被任何一個大於 1
// 的完全平方數整除，則稱其為平方自由數 例如：6 = 2 * 3 是平方自由數；12 = 2^2 *
// 3 含有 4，因此不是平方自由數
//
// 預處理 core[x]：將每個 1 <= x < MX 映射為它的「平方核」(square-free core)
// 任意正整數 n 都可以唯一分解為：n = 核心平方自由數 * (某個完全平方數)
//            即：n = core[n] * (j^2)
// 例如：72 = 2^3 * 3^2 = (2^1) * (6^2) → core[72] = 2
//
// 演算法思路：
// - 由小到大枚舉 i：
//   若目前 core[i] == 0，代表 i 尚未被「更小的平方核」標記過，
//   因此 i 不含任何平方因子，是一個平方自由數，可以當作某些數的平方核。
// - 接著枚舉 j >= 1，將所有形如 n = i * j^2 的數標記為 core[n] = i
//   如此保證：n 的平方核就是最小的平方自由因子 i，使得 n / i 為完全平方數。
//
// 複雜度：
//   對每個 i，j 的範圍約為 sqrt(MX / i)，
//   總複雜度約為 MX * (1 + 1/2^2 + 1/3^2 + ...) = O(MX)
auto init = [] {
  for (int i = 1; i < MX; ++i)
    // 若 core[i] 仍為 0，表示 i 尚未被任何較小平方核 k 以 k * j^2 形式標記，
    // 因此 i 不含平方因子，是平方自由數，可作為平方核。
    if (core[i] == 0)
      // 將所有 n = i * j^2 的數字標記為平方核 i
      // j 從 1 開始：當 j = 1 時，core[i] 也會被設為 i（自己是自己的平方核）
      for (int j = 1; 1LL * i * j * j < MX; ++j)
        core[i * j * j] = i;
  return 0;
}();

class Solution {
public:
  long long sumOfAncestors(int n, vector<vector<int>> &edges,
                           vector<int> &nums) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
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