class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    ListNode dummy(-1, head);
    ListNode *slow = &dummy, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return dummy.next;
  }
};