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
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int max_profit = 0;
        int cheapest = prices[0];
        for(int i=1; i<prices.size(); i++){
            max_profit = max(max_profit, prices[i] - cheapest);
            cheapest = min(cheapest, prices[i]);
        }
        return max_profit;
    }
};