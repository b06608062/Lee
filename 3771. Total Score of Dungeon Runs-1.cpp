// mark
// 1981
// 貢獻法 + 前綴和二分
// 橫看成嶺側成峰
// 看每個 i 對結果的貢獻：以 i 結束的區間 [j..i]，j ∈ [0..i]
// 需要滿足 hp - (pref[i + 1] - pref[j]) >= requirement[i]
// 即 pref[j] >= requirement[i] + pref[i + 1] - hp
class Solution {
public:
  long long totalScore(int hp, vector<int> &damage, vector<int> &requirement) {
    int n = damage.size();
    vector<long long> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + damage[i - 1];

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      int c = requirement[i] + pref[i + 1] - hp;
      int j = lower_bound(pref.begin(), pref.begin() + i + 1, c) - pref.begin();
      res += i - j + 1;
    }

    return res;
  }
};