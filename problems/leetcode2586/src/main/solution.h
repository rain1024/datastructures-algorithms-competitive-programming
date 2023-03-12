#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool is_vowel(string s) {
    int n = s.size();
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    if (find(vowels.begin(), vowels.end(), s[0]) == vowels.end()) {
      return false;
    }
    if (find(vowels.begin(), vowels.end(), s[n - 1]) == vowels.end()) {
      return false;
    }
    return true;
  }

  int vowelStrings(vector<string>& words, int left, int right) {
    int count = 0;
    for (int i = left; i <= right; i++) {
      if (is_vowel(words[i])) {
        count++;
      }
    }
    return count;
  }
};