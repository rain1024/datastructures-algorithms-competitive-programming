class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*> lists) {
    struct compare {
     public:
      bool operator()(ListNode* a, ListNode* b)  // overloading both operators
      {
        return a->val > b->val;
      }
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;

    for (auto list : lists) {
      ListNode* tmp = list;
      while (tmp != nullptr) {
        pq.push(tmp);
        tmp = tmp->next;
      }
    }


    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "head " << endl;

    while (!pq.empty()) {
      ListNode* node = pq.top();
      pq.pop();
      cout << "node = " << node->val << endl;

      if (head == nullptr) {
        head = node;
        tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }
    if(tail != nullptr){
        tail->next = nullptr;
    }
    return head;
  }
};