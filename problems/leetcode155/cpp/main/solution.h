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

class MinStack {
 private:
  stack<pair<int, int>> s;

 public:
  MinStack() {}

  void push(int val) {
    if (s.empty()) {
      s.push({val, val});
    } else {
      s.push({val, min(val, getMin())});
    }
  }

  void pop() { s.pop(); }

  int top() { return s.top().first; }

  int getMin() { return s.top().second; }
};
