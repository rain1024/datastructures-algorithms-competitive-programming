#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for (auto num : nums) {
      if (s.find(num) != s.end()) {
        return true;
      }
      s.insert(num);
    }
    return false;
  }
};