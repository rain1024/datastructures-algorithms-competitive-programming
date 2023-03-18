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
  ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode* tmp = head;
    while (tmp != nullptr) {
      n += 1;
      tmp = tmp->next;
    }
    int position = 0;
    if (n % 2 == 0) {
      position = n / 2;
    } else {
      position = (n - 1) / 2;
    }
    tmp = head;
    int i = 0;
    while (i < position) {
      tmp = tmp->next;
      i += 1;
    }
    return tmp;
  }
};