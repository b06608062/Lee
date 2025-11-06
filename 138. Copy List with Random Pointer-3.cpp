// O(N) time, O(1) space solution
class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    // Pass 1: interleave copy nodes with originals
    for (Node *cur = head; cur;) {
      Node *copy = new Node(cur->val);
      copy->next = cur->next;
      cur->next = copy;
      cur = copy->next;
    }

    // Pass 2: assign random pointers for copies
    for (Node *cur = head; cur; cur = cur->next->next) {
      if (cur->random) {
        cur->next->random = cur->random->next;
      }
    }

    // Pass 3: unweave to restore original and extract copy
    Node *copyHead = head->next;
    for (Node *cur = head; cur;) {
      Node *copy = cur->next;
      cur->next = copy->next; // restore original next
      copy->next = copy->next ? copy->next->next : nullptr; // link copies
      cur = cur->next; // advance original pointer
    }

    return copyHead;
  }
};