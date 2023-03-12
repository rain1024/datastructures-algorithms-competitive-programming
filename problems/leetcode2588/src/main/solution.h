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
    long long beautifulSubarrays(vector<int>& nums) {
        long count = 0;
        map<int, int> m;
        int n = nums.size();
        int xo = 0;
        for(int i=0; i<n; i++){
            xo ^= nums[i];
            if(xo == 0){
                count++;
            }
            
            if(m.find(xo) != m.end()){
                count+= m[xo];
            }
            m[xo] += 1;
        }
        return count;
    }
};