class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode dummy(-1, head);
    ListNode *cur = &dummy;

    while (cur->next && cur->next->next) {
      ListNode *p1 = cur->next;
      ListNode *p2 = cur->next->next;
      p1->next = p2->next;
      p2->next = p1;
      cur->next = p2;
      cur = p1;
    }

    return dummy.next;
  }
};