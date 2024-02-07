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
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] - nums[j] <= nums[j]){
                    m = max(m, nums[i] ^ nums[j]);
                }
            }
        }
        return m;
    }
};