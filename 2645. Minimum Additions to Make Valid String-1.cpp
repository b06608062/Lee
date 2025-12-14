// mark
// 1478
// Greedy 模擬
class Solution {
public:
  int addMinimum(string word) {
    int need = 0; // 0:'a', 1:'b', 2:'c'
    int add = 0;

    for (char ch : word) {
      int x = ch - 'a';
      while (need != x) { // 插入缺的字
        add++;
        need = (need + 1) % 3;
      }
      // match 了，就消耗這個字元，期待下一個
      need = (need + 1) % 3;
    }

    // 最後補齊到 "abc" 結尾
    add += (3 - need) % 3;
    return add;
  }
};
