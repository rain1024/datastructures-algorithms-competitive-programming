#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c: s){
            m[c] += 1;
        }
        int output = 0;
        int has_odd = 0;
        for(auto iter: m){
            int c = iter.second;
            if(c % 2 == 0){
                output += c;
            } else {
                has_odd = 1;
                output += c - 1;
            }
        }
        output += has_odd;
        return output;
    }
};