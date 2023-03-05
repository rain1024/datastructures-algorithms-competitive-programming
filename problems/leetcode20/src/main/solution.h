#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char val;
        for(auto c: s){
            if(c == ')' || c == ']' || c == '}'){
                if(st.empty()){
                    return false;
                }
                val = st.top();
                if(c == ')' && val != '('){
                    return false;
                }
                if(c == ']' && val != '['){
                    return false;
                }
                if(c == '}' && val != '{'){
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};