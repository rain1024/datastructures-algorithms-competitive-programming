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
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> ms;
    unordered_map<char, char> mt;
    for (int i = 0; i < s.size(); i++) {
      char u = s[i];
      char v = t[i];
      if (ms.find(u) == ms.end()) {
        ms[u] = v;
      }
      if (mt.find(v) == mt.end()) {
        mt[v] = u;
      }
      if (ms[u] != v || mt[v] != u) {
        return false;
      }
    }
    return true;
  }
};