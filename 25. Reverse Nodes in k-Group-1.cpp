class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    int n = 0;
    ListNode *cur = head;
    while (cur) {
      n++;
      cur = cur->next;
    }

    ListNode dummy;
    ListNode *p0 = &dummy;
    p0->next = head;
    cur = p0->next;
    while (n >= k) {
      n -= k;
      ListNode *prev = nullptr;
      for (int i = 0; i < k; ++i) {
        ListNode *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
      }
      ListNode *nxt = p0->next;
      p0->next->next = cur;
      p0->next = prev;
      p0 = nxt;
    }

    return dummy.next;
  }
};