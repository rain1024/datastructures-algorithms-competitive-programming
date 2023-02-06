#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> solve(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      v.push_back(i);
    }
    return v;
  }
};