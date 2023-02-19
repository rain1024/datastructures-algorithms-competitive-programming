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
  string hash_string(string s) {
    sort(s.begin(), s.end());
    return s;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (auto str : strs) {
      string h = hash_string(str);
      m[h].push_back(str);
    }
    vector<vector<string>> output;
    for (auto iter : m) {
      output.push_back(iter.second);
    }
    return output;
  }
};