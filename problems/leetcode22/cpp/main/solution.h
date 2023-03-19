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
  vector<string> output;

  void backtrack(int open, int close, int n, string current) {
    if (open == n && close == n) {
      output.push_back(current);
    }

    if (open < n) {
      backtrack(open + 1, close, n, current + "(");
    }
    if (close < open) {
      backtrack(open, close + 1, n, current + ")");
    }
  }
  vector<string> generateParenthesis(int n) {
    backtrack(0, 0, n, "");
    return output;
  }
};