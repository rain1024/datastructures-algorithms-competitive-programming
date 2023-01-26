#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
       int n_subsets = 1 << n;
       vector<vector<int>> subsets;
       for(int i=0; i<n_subsets; i++){
           vector<int> subset;
           for(int j=0; j<n; j++){
               if(i & (1 << j)){
                   subset.push_back(nums[j]);
               }
           }
           subsets.push_back(subset);
       }
       return subsets;
    }
};