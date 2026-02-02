// mark
// Convex Hull 入門
// Andrew's monotone chain

class Solution {
public:
  // 定義叉積運算：判斷向量 OA 與 OB 的轉向
  // 回傳值 > 0: 逆時針, < 0: 順時針, 0: 共線
  long long crossProduct(const vector<int> &a, const vector<int> &b,
                         const vector<int> &c) {
    return (long long)(b[0] - a[0]) * (c[1] - b[1]) -
           (long long)(b[1] - a[1]) * (c[0] - b[0]);
  }

  vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
    int n = trees.size();
    if (n <= 2)
      return trees;

    // Step 1: Sorting
    sort(trees.begin(), trees.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
         });

    vector<vector<int>> hull;

    // Step 2: Build Lower Hull
    for (int i = 0; i < n; ++i) {
      while (hull.size() >= 2 &&
             crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
        hull.pop_back();
      }
      hull.push_back(trees[i]);
    }

    // Step 3: Build Upper Hull
    // 為了包含共線點，我們從倒數第二個點開始往回掃
    int lowerSize = hull.size();
    for (int i = n - 2; i >= 0; --i) {
      while (hull.size() > lowerSize &&
             crossProduct(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
        hull.pop_back();
      }
      hull.push_back(trees[i]);
    }

    // Step 4: 去除重複點 (起點與終點會重複計算)
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());

    return hull;
  }
};