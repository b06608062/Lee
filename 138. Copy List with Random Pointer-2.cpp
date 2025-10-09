class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  unordered_map<Node *, Node *> umap;
  Node *copyRandomList(Node *head) {
    umap[nullptr] = nullptr;

    return helper(head);
  }

  Node *helper(Node *cur) {
    if (umap.count(cur))
      return umap[cur];

    Node *newNode = new Node(cur->val);
    umap[cur] = newNode;
    newNode->next = helper(cur->next);
    newNode->random = helper(cur->random);

    return newNode;
  }
};