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

class Solution {
 public:
  int partitionString(string s) {
    set<char> st;
    int count = 1;
    for (auto c : s) {
      if (st.find(c) != st.end()) {
        count++;
        st = {c};
      } else {
        st.insert(c);
      }
    }
    return count;
  }
};