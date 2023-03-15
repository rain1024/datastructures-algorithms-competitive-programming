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
  int pivotIndex(vector<int>& nums) {
    int right = 0;
    int left = 0;
    for (auto num : nums) {
      right += num;
    }
    for (int i = 0; i < nums.size(); i++) {
      right -= nums[i];
      if (left == right) {
        return i;
      }
      left += nums[i];
    }
    return -1;
  }
};