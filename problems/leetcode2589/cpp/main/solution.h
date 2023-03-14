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
  int findMinimumTime(vector<vector<int>>& tasks) {
    vector<bool> used(2001, false);
    sort(begin(tasks), end(tasks),
         [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
    int total_time = 0;
    for (auto task : tasks) {
      int s = task[0], e = task[1], d = task[2];
      for (int i = s; i <= e; i++) {
        if (used[i]) {
          d--;
        }
      }

      while (d > 0) {
        if (!used[e]) {
          total_time++;
          d--;
          used[e] = true;
        }
        e--;
      }
    }

    return total_time;
  }
};