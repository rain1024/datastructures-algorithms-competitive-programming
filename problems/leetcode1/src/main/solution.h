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
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int left;
    for (int i = 0; i < nums.size(); i++) {
      left = target - nums[i];
      if (m.find(left) != m.end()) {
        return {i, m[left]};
      }
      m[nums[i]] = i;
    }

    return {-1, -1};
  }
};