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
  vector<int> productExceptSelf(vector<int>& nums) {
    int p = 1;
    int zeros = 0;
    for (auto num : nums) {
      if (num != 0) {
        p *= num;
      } else {
        zeros++;
      }
    }
    vector<int> v;
    for (auto num : nums) {
      int val;
      if (zeros > 1) {
        val = 0;
      } else if (zeros == 1) {
        val = num != 0 ? 0 : p;
      } else {
        val = p / num;
      }
      v.push_back(val);
    }
    return v;
  }
};