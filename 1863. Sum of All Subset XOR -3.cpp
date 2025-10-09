/*
把問題拆成「每個 bit 的貢獻」來算。
為什麼答案是 (OR) * 2^(n-1)？
1) 固定某個位元 j（值 = 1<<j），設 t_j = 陣列中該位為 1 的元素個數。
2) XOR 的第 j 位要為 1，必須從這 t_j 個元素中選「奇數個」。奇偶對半，選法數 =
2^(t_j-1)（若 t_j=0，則為 0）。
3) 其他在該位為 0 的元素怎麼選都不影響該位，共有 2^(n - t_j) 種選法。
4) 所以第 j 位為 1 的子集總數 = 2^(t_j-1) * 2^(n - t_j) =
2^(n-1)（只要 t_j>0）。 5) 把所有出現過的位元相加，等同於 (所有元素的 bitwise
OR) * 2^(n-1)。
*/

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int OR = 0;
    for (int x : nums)
      OR |= x;

    return OR << (nums.size() - 1);
  }
};
