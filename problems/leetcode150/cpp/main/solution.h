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
  int evalRPN(vector<string>& tokens) {
    set<string> operators = {"+", "-", "*", "/"};
    stack<int> s;
    int output;
    for (auto c : tokens) {
      if (operators.count(c) > 0) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (c == "+") {
          output = b + a;
        } else if (c == "-") {
          output = b - a;
        } else if (c == "*") {
          output = b * a;
        } else {
          output = b / a;
        }
        s.push(output);
      } else {
        s.push(stoi(c));
      }
    }
    return s.top();
  }
};