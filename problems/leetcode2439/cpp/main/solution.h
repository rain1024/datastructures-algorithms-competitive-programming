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
  int minimizeArrayValue(vector<int>& nums) {
    long long m = 0;
    long long prefix_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      prefix_sum += nums[i];
      m = max(m, (prefix_sum + i) / (i + 1));
    }
    return m;
  }
};