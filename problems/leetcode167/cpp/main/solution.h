#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int left = 0;
    int right = n - 1;
    int sum = numbers[left] + numbers[right];
    // int count = 0;
    // while(sum != target && count < 10){
    while (sum != target) {
      // cout << left << ", " << right << endl;
      if (sum > target) {
        right--;
      } else {
        left++;
      }
      sum = numbers[left] + numbers[right];
      // count++;
    }
    // cout << left << ", " << right << endl;
    return {left + 1, right + 1};
  }
};