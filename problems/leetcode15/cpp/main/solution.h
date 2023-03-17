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
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
      int a = nums[i];
      int lo = i + 1;
      int hi = n - 1;
      while (lo < hi) {
        int b = nums[lo];
        int c = nums[hi];
        if (a + b + c == 0) {
          ans.push_back({a, b, c});
          while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
          while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
          lo++;
          hi--;
        } else if (a + b + c > 0) {
          hi--;
        } else {
          lo++;
        }
      }
      while (i < n - 2 && nums[i] == nums[i + 1]) i++;
    }
    return ans;
  }
};