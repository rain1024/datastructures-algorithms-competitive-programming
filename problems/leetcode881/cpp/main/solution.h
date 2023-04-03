#include <algorithm>
#include <climits>
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
  int numRescueBoats(vector<int>& people, int limit) {
    sort(begin(people), end(people), greater<int>());
    int lo = 0;
    int hi = people.size() - 1;
    int count = 0;
    while (lo <= hi) {
      if (people[lo] >= limit) {
        lo++;
      } else if (people[lo] + people[hi] > limit) {
        lo++;
      } else {
        lo++;
        hi--;
      }
      count++;
    }
    return count;
  }
};