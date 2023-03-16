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
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i =0 ; i < nums.size() - 1; i++){
            left[i+1] = left[i] + nums[i];
        }
        for(int i = n-2 ; i>=0; i--){
            right[i] = right[i+1] + nums[i+1];
        }
        vector<int> answer(n, 0);
        for(int i=0; i<n; i++){
            answer[i] = abs(left[i] - right[i]);
        }
        return answer;
    }
};