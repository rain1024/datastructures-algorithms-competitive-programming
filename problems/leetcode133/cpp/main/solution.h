#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  map<int, Node*> m;
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    Node* n = new Node(node->val);
    m[node->val] = n;
    vector<Node*> nbs;
    for (auto nb : node->neighbors) {
      if (m.find(nb->val) != m.end()) {
        nbs.push_back(m[nb->val]);
      } else {
        nbs.push_back(cloneGraph(nb));
      }
    }
    n->neighbors = nbs;
    return n;
  }
};