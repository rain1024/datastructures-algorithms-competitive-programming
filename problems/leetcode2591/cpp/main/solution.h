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

class Solution {
 public:
  int distMoney(int money, int children) {
    if (money < children) {
      return -1;
    }
    int max_k = 0;
    for (int k = 0; k <= 30; k++) {
      int total = k * 8;
      int remain_children = children - k;
      int remain_money = money - total;
      if (remain_money < remain_children) {
        break;
      }
      if (remain_money == remain_children) {
        max_k = max(max_k, k);
      }
      if (remain_money > remain_children) {
        if (remain_money == 4 && remain_children == 1) {
          break;
        }
        if (remain_money > 0 && remain_children == 0) {
          break;
        }
        max_k = max(max_k, k);
      }
    }
    return max_k;
  }
};