/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();

    ListNode dummy;
    ListNode *cur = &dummy;
    auto comp = [](auto &a, auto &b) { return a->val > b->val; };
    // min heap
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

    for (int i = 0; i < n; ++i) {
      ListNode *p = lists[i];
      if (p)
        pq.push(p);
    }

    while (!pq.empty()) {
      ListNode *p = pq.top();
      pq.pop();
      cur->next = p;
      cur = p;
      p = p->next;
      if (p)
        pq.push(p);
    }

    return dummy.next;
  }
};