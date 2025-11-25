// bubble sort
// TLE

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
      bool swapped = false;
      for (int j = 0; j < n - 1 - i; ++j) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          swapped = true;
        }
      }
      if (!swapped)
        return nums;
    }

    return nums;
  }
};

struct Node {
  int val;
  Node *next;
  Node(int v) : val(v), next(nullptr) {}
};

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    Node dummy(-1);
    Node *cur = &dummy;
    for (auto x : nums) {
      cur->next = new Node(x);
      cur = cur->next;
    }

    for (int i = 0; i < n - 1; ++i) {
      bool swaped = false;
      cur = &dummy;
      for (int j = 0; j < n - 1 - i; ++j) {
        if (cur->next->val > cur->next->next->val) {
          Node *p1 = cur->next, *p2 = cur->next->next;
          cur->next = p2;
          p1->next = p2->next;
          p2->next = p1;
          swaped = true;
        }
        cur = cur->next;
      }
      if (!swaped)
        break;
    }

    vector<int> res;
    cur = dummy.next;
    while (cur) {
      res.push_back(cur->val);
      cur = cur->next;
    }

    return res;
  }
};