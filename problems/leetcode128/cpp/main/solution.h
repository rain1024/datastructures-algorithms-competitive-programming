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
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    sort(begin(nums), end(nums));
    int max_seq = 1;
    int cur_seq = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] == 1) {
        cur_seq++;
        max_seq = max(max_seq, cur_seq);
      } else if (nums[i] - nums[i - 1] == 0) {
        continue;
      } else {
        cur_seq = 1;
      }
    }
    return max_seq;
  }
};