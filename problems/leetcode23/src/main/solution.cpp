#include "solution.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

ListNode* createLinkedList(vector<int> nums) {
  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  for (auto num : nums) {
    ListNode* node = new ListNode(num);

    if (head == nullptr) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "2.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // now read from file as if it were cin
  vector<ListNode*> lists;
  string line;
  while (getline(cin, line)) {
    vector<int> v = get_vectors(line);
    ListNode* head = createLinkedList(v);
    lists.push_back(head);
  }

  Solution solution;
  ListNode* result = solution.mergeKLists(lists);

  cout << "result = " << result << endl;
  return 0;
}