#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include "solution.h"

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  // get input
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++){
    cin >> nums[i];
  }
  int target;
  cin >> target;

  Solution solution;
  vector<int> v = solution.twoSum(nums, target);

  // print output
  for(auto i: v){
    cout << i << endl;
  }
  
  return 0;
}