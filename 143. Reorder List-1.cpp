struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;

    ListNode dummy;
    ListNode *sslow = &dummy;
    sslow->next = head;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      sslow = sslow->next;
      slow = slow->next;
      fast = fast->next->next;
    }

    sslow->next = nullptr;

    ListNode *prev = nullptr, *cur = slow;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }

    ListNode *list1 = head;
    ListNode *list2 = prev;
    cur = &dummy;
    while (list1 && list2) {
      cur->next = list1;
      list1 = list1->next;
      cur = cur->next;
      cur->next = list2;
      list2 = list2->next;
      cur = cur->next;
    }
  }
};