// mark
// 1657
// 考慮左半部數字 - 1, 0, +1 三種可能性，反轉構造回文並計算差值
// 如果 n 是奇數，左半部數字需包含正中間的比特
// 目的在於左半部盡量接近原數字，這樣差值才會最小 + 2, -2 會導致整體差值更大
class Solution {
public:
  vector<int> minOperations(vector<int> &nums) {
    for (int &x : nums) {
      if (x == 1) {
        x = 0;
        continue;
      }
      int res = INT_MAX;
      int n = bit_width((uint32_t)x);
      int m = n / 2;
      int left = x >> m;
      for (int l = left - 1; l <= left + 1; l++) {
        // 左半反轉到右半
        // 如果 n 是奇數，先去掉正中間的比特，再反轉
        int right = __builtin_bitreverse32(l >> (n % 2)) >> (32 - m);
        int pal = l << m | right;
        res = min(res, abs(x - pal));
      }
      x = res;
    }
    return nums;
  }
};

class Solution {
public:
  string toBinary(int x) {
    string s = "";
    while (x) {
      s += (x % 2) + '0';
      x /= 2;
    }
    return s;
  }

  bool isPalindrome(int x) {
    string bin = toBinary(x);
    string rev = bin;
    reverse(rev.begin(), rev.end());

    return bin == rev;
  }

  vector<int> minOperations(vector<int> &nums) {
    vector<int> palindromes;
    for (int i = 1; i <= 8192; ++i)
      if (isPalindrome(i))
        palindromes.push_back(i);

    vector<int> res;
    for (int num : nums) {
      // 在 palindromes 裡用 binary search 找第一個 >= num 的回文
      auto it = lower_bound(palindromes.begin(), palindromes.end(), num);

      int best = INT_MAX;

      // 候選一：第一個 >= num 的回文
      if (it != palindromes.end()) {
        best = min(best, abs(*it - num));
      }

      // 候選二：最後一個 < num 的回文（it 的前一個）
      if (it != palindromes.begin()) {
        --it;
        best = min(best, abs(*it - num));
      }

      res.push_back(best);
    }

    return res;
  }
};