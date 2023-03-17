#include "solution.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // get input and output
  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  ListNode* l = Solution().mergeTwoLists(l1, l2);

  return 0;
}