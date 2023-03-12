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
    int maxScore(vector<int>& nums) {
        int score = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        long long prefix_sum = 0;
        for(auto num: nums){
            prefix_sum += (long long) num;
            if(prefix_sum > 0){
                score += 1;
            }
        }
        return score;
    }
};