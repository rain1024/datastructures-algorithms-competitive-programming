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
  long long findScore(vector<int>& nums) {
    int n = nums.size();
    vector<int> s = nums;
    vector<bool> mark(n, false);
    vector<pair<int, int>> np;
    for (int i = 0; i < nums.size(); i++) {
      np.push_back({nums[i], i});
    }

    auto cmp = [](pair<int, int> a, pair<int, int> b) {
      return a.first != b.first ? a.first < b.first : a.second < b.second;
    };
    sort(begin(np), end(np), cmp);

    long long score = 0;
    for (auto iter : np) {
      int val = iter.first;
      int idx = iter.second;
      if (!mark[idx]) {
        score += val;
        if (idx > 0) {
          mark[idx - 1] = true;
        }
        if (idx < n - 1) {
          mark[idx + 1] = true;
        }
      }
    }

    return score;
  }
};