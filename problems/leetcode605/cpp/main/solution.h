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
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    int l = flowerbed.size();
    for (int i = 0; i < l; i++) {
      if ((flowerbed[i] == 1) || (i > 0 && flowerbed[i - 1] == 1) ||
          (i < l - 1 && flowerbed[i + 1] == 1))
        continue;
      flowerbed[i] = 1;
      n--;
      if (n == 0) {
        return true;
      }
    }
    return false;
  }
};