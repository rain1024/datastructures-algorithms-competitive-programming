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
  bool isSubsequence(string s, string t) {
    int slow = 0;
    int fast = 0;
    while (fast < t.size() && slow < s.size()) {
      if (t[fast] == s[slow]) {
        slow++;
      }
      fast++;
    }
    return slow == s.size();
  }
};