struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right)
      return head;

    ListNode dummy;
    dummy.next = head;

    ListNode *front = &dummy;
    for (int i = 0; i < left - 1; ++i)
      front = front->next;

    ListNode *end = &dummy;
    for (int i = 0; i <= right; ++i)
      end = end->next;

    ListNode *mid = front->next;
    ListNode *prev = nullptr;
    ListNode *cur = mid;
    while (cur != end) {
      ListNode *nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    front->next = prev;
    mid->next = end;

    return dummy.next;
  }
};