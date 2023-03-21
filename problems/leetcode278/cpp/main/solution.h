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
 private:
  int n;
  int bad;

 public:
  Solution(int n, int bad) {
    this->n = n;
    this->bad = bad;
  }

  bool isBadVersion(int version) { return version >= this->bad; }

  int firstBadVersion(int n) {
    // Sample
    //     Version : good good good good bad bad bad
    // isBadVersion: false false false false true true true
    int lo = 1;
    int hi = n;
    int mid;
    int firstBad;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (isBadVersion(mid)) {
        hi = mid - 1;
        firstBad = mid;
      } else {
        lo = mid + 1;
      }
    }
    return firstBad;
  }
};