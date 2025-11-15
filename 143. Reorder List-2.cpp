class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = nullptr, *cur = slow;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    ListNode *head1 = head, *head2 = prev;
    while (head2->next) {
      ListNode *nxt1 = head1->next;
      ListNode *nxt2 = head2->next;
      head1->next = head2;
      head2->next = nxt1;
      head1 = nxt1;
      head2 = nxt2;
    }
  }
};