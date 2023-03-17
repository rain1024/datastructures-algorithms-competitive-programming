#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* ans = new ListNode(head->val);
    ListNode* tmp = head;
    while (tmp->next) {
      ans = new ListNode(tmp->next->val, ans);
      tmp = tmp->next;
    }
    return ans;
  }
};