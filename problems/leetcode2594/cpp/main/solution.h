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
    long long repairCars(vector<int>& ranks, int cars) {
        sort(begin(ranks), end(ranks));
        
        long long hi = ranks[0] * (long long) cars * (long long) cars;
        long long lo = 0;
        while(lo < hi){
            long long t = 0;
            long long mid = (hi + lo) / 2;
            for(int i=0; i<ranks.size(); i++){
                t += floor(sqrt(mid * 1.0 / ranks[i]));
            }
            // cout << "lo = " << lo << ", mid = " << mid << ", t = " << t << endl;
            if(t >= cars){
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};