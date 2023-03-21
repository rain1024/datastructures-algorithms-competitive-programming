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
  int search(vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (target < nums[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return -1;
  }
};