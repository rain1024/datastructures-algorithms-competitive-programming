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
    int romanToInt(string s) {
        map<string, int> values;
        values["M"] = 1000;
        values["D"] = 500;
        values["C"] = 100;
        values["L"] = 50;
        values["X"] = 10;
        values["V"] = 5;
        values["I"] = 1;
        int n = s.length();
        if(n == 0){
            return 0;
        }
        if(n >= 2){
            if(s.substr(0, 2) == "CM"){
                return 900 + this->romanToInt(s.substr(2, n-2));
            }
            if(s.substr(0, 2) == "CD"){
                return 400 + this->romanToInt(s.substr(2, n-2));
            }
            if(s.substr(0, 2) == "XC"){
                return 90 + this->romanToInt(s.substr(2, n-2));
            }
            if(s.substr(0, 2) == "XL"){
                return 40 + this->romanToInt(s.substr(2, n-2));
            }
            if(s.substr(0, 2) == "IX"){
                return 9 + this->romanToInt(s.substr(2, n-2));
            }
            if(s.substr(0, 2) == "IV"){
                return 4 + this->romanToInt(s.substr(2, n-2));
            }
        }
        if(n >= 1){
            return values[s.substr(0, 1)] + this->romanToInt(s.substr(1, n-1));
        }
        return 0;
    }
};