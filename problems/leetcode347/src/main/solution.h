#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for(auto num: nums){
            counter[num] += 1;
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        vector<pair<int, int>> sorted_counter(counter.begin(), counter.end());
        sort(sorted_counter.begin(), sorted_counter.end(), cmp);
        vector<int> topK;
        transform(
            sorted_counter.begin(),
            next(sorted_counter.begin(), k),
            back_inserter(topK), [](const auto& p){
                return p.first;
            });
        return topK;
    }
};