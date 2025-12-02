class Solution {
public:
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode dummy(-1, list1);
    ListNode *front = &dummy, *tail = &dummy;
    int diff = b - a + 2;
    while (diff--)
      tail = tail->next;
    while (a--) {
      front = front->next;
      tail = tail->next;
    }
    front->next = list2;
    while (list2->next)
      list2 = list2->next;
    list2->next = tail;

    return dummy.next;
  }
};