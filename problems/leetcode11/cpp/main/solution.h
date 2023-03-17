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
  int maxArea(vector<int>& height) {
    int m = 0;
    int lo = 0;
    int hi = height.size() - 1;
    int area;
    while (lo < hi) {
      area = min(height[lo], height[hi]) * (hi - lo);
      m = max(m, area);
      if (height[lo] <= height[hi]) {
        lo++;
      } else {
        hi--;
      }
    }
    return m;
  }
};