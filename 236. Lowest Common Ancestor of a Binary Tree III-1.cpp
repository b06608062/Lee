class Solution {
public:
  Node *lowestCommonAncestor(Node *p, Node *q) {
    unordered_set<Node *> uset;
    while (p) {
      uset.insert(p);
      p = p->parent;
    }
    while (q) {
      if (uset.count(q))
        return q;
      q = q->parent;
    }
    return nullptr;
  }
};