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
  int maximizeGreatness(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int slow = 0;
    int fast = 1;
    int count = 0;
    while (fast < nums.size()) {
      if (nums[fast] > nums[slow]) {
        count++;
        fast++;
        slow++;
      } else {
        fast++;
      }
    }
    return count;
  }
};