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
  int k, n;
  cin >> n >> k;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }

  Solution solution;
  vector<int> v = solution.topKFrequent(nums, k);

  // print output
  for(auto i: v){
    cout << i << " ";
  }
  
  return 0;
}