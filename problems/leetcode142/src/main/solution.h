#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && slow) {
      if (!fast->next || !fast->next->next) {
        return NULL;
      }
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }

    while (slow != head) {
      slow = slow->next;
      head = head->next;
    }
    return slow;
  }
};