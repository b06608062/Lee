struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    vector<ListNode *> arr;
    ListNode *cur = head;
    while (cur) {
      arr.push_back(cur);
      cur = cur->next;
    }

    int size = arr.size();
    if (size == 1)
      return nullptr;

    if (n == size)
      return head->next;

    if (n == 1) {
      arr[size - 2]->next = nullptr;
      return head;
    }

    ListNode *prev = arr[size - n - 1], *next = arr[size - n + 1];
    prev->next = next;

    return head;
  }
};