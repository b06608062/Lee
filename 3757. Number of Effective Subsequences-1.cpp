// SOS DP + 容斥原理
constexpr static int MOD = 1'000'000'007;
constexpr static int MAX_N = 100'001;
int pow2[MAX_N];

// 預處理 2 的冪次（pow2[i] = 2^i mod MOD）
int init = [] {
  pow2[0] = 1;
  for (int i = 1; i < MAX_N; i++) {
    pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
  }
  return 0;
}();

class Solution {
public:
  int countEffective(vector<int> &nums) {
    int n = nums.size();

    // or_ = 整個陣列 nums 的按位或
    int or_ = 0;
    for (int x : nums)
      or_ |= x;

    // w = or_ 的二進位長度（需要多少 bit 來表示）
    int w = bit_width((uint32_t)or_);

    // U = 所有可能的 mask 數量（0 ~ 2^w - 1）
    int U = 1 << w;

    // ---------- 1. 初始 f[0][S]：nums 中「值恰好等於 S」的元素個數 ----------
    vector<int> base(U);
    for (int x : nums)
      base[x]++;

    // f[i][S] 的定義：
    //   已經處理完 bit 0..i-1（低位共 i 個 bit）之後，
    //   在「所有 ≥ i 的高位 bit 固定為 S 的樣子」的條件下，
    //   nums 中「是 S 的子集」的元素個數。
    //
    // i = 0 時，尚未處理任何 bit，
    // 此時「所有 bit 都完全固定為 S」，只能是「值恰好等於 S」，
    // 所以 f[0][S] = base[S]。
    vector<vector<int>> f(w + 1, vector<int>(U));
    f[0] = base;

    // 逐一處理每一個 bit i（從低位到高位）
    for (int i = 0; i < w; ++i) {
      int bit = 1 << i; // 第 i 個 bit 對應的 mask

      for (int S = 0; S < U; ++S) {
        // 先把「不動第 i 位」的情況繼承下來
        f[i + 1][S] = f[i][S];

        // 若 S 的第 i 位為 1，則有兩種情況可以合併：
        //   1. 保留第 i 位為 1  → f[i][S]
        //   2. 把第 i 位當作 0  → f[i][S ^ bit]
        // 所以 f[i+1][S] = f[i][S] + f[i][S ^ bit]
        if (S & bit)
          f[i + 1][S] += f[i][S ^ bit];
      }
    }

    // 執行完所有 bit 後：
    // f[w][S] = nums 中「bitmask 是 S 的子集」的元素個數
    const vector<int> &cntSubset = f[w];

    // ---------- 3. 容斥原理：計算「按位或恰好等於 or_」的子序列數 ----------
    // #[OR = 110] = +#[OR ⊆ 110] -#[OR ⊆ 010] -#[OR ⊆ 100] +#[OR ⊆ 000]
    // res 一開始是所有子序列的個數（所有刪除方式），也就是 2^n
    long long res = pow2[n];

    // sub 枚舉 or_ 的所有子集合（包含 0 和 or_ 本身）
    int sub = or_;
    do {
      // or_ ^ sub：在 or_ 的 bit 集合中，和 sub 不同的位置
      // diffBits：or_ 和 sub 相差的 bit 個數
      int diffBits = popcount((uint32_t)(or_ ^ sub));

      // 若差的 bit 數為偶數，符號為 +1；奇數，符號為 -1
      // 這就是容斥原理中的 + - + - ...
      int sign = (diffBits % 2 == 0) ? 1 : -1;

      // cnt = nums 中「是 sub 的子集」的元素個數
      int cnt = cntSubset[sub];

      // ways = 從這些元素中任意選/不選形成的子序列個數 = 2^cnt
      long long ways = pow2[cnt];

      // res 減去（或加上）這一部分的「OR 是 or_ 的子序列」數
      res -= sign * ways;

      // 透過位運算枚舉下一個 sub：
      // (sub - 1) & or_ 會在 or_ 的子集合中往前走
      sub = (sub - 1) & or_;
    } while (sub != or_); // 回到初始值時結束

    res %= MOD;
    if (res < 0)
      res += MOD;

    // res 現在就是「有效子序列」數量：刪除後 OR 變小的子序列數
    return (int)res;
  }
};
