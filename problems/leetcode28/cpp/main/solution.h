#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if(pos != string::npos){
            return (int) pos;
        } else {
            return -1;
        }
    }
};