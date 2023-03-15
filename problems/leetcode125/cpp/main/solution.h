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
  bool isPalindrome(string s) {
    string s0 = "";
    for (int i = 0; i < s.size(); i++) {
      if (isalnum(s[i])) {
        s0 += tolower(s[i]);
      }
    }
    string t = s0;
    reverse(t.begin(), t.end());
    return t == s0;
  }
};