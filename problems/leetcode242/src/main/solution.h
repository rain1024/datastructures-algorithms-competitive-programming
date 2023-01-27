#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int n = s.size();
    unordered_map<char, int> ms, mt;
    for (auto c : s) {
      ms[c] += 1;
    }
    for (auto c : t) {
      mt[c] += 1;
    }
    char c;
    for (auto item : ms) {
      c = item.first;
      if (ms[c] != mt[c]) {
        return false;
      }
    }

    for (auto item : mt) {
      c = item.first;
      if (ms[c] != mt[c]) {
        return false;
      }
    }
    return true;
  }
};