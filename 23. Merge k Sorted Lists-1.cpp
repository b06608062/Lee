class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode dummy;
    ListNode *cur = &dummy;

    // min heap
    auto comp = [](auto &a, auto &b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

    for (auto &head : lists)
      if (head)
        pq.push(head);

    while (!pq.empty()) {
      auto top = pq.top();
      pq.pop();
      cur->next = top;
      cur = top;
      if (top->next)
        pq.push(top->next);
    }

    return dummy.next;
  }
};