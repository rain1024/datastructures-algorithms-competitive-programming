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
  long long zeroFilledSubarray(vector<int>& nums) {
    int n = 0;
    long long count = 0;
    for (auto num : nums) {
      if (num == 0) {
        n += 1;
      } else {
        count += (long long)n * (n + 1) / 2;
        n = 0;
      }
    }
    count += (long long)n * (n + 1) / 2;
    return count;
  }
};