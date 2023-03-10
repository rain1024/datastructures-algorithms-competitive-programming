#include "solution.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ListNode*> vln(n);

  int val;
  for(int i=0; i<n; i++){
    cin >> val;
    vln[i] = new ListNode(val);
  }
  for (int i = 0; i < n-1; i++) {
    vln[i]->next = vln[i + 1];
  }

  int tail;
  cin >> tail;
  if (tail != -1) {
    vln[n - 1]->next = vln[tail];
  }

  ListNode* head = vln[0];

  Solution solution;
  ListNode* result = solution.detectCycle(head);

  if (result == NULL) {
    cout << "no cycle" << endl;
  } else {
    for(int i=0; i<n; i++){
      if(vln[i] == result){
        cout << "tail connects to node index " << i << endl;
        break;
      }
    }
  }

  return 0;
}