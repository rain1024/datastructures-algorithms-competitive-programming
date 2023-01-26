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

  Solution solution;
  vector<vector<int>> subsets = solution.subsets(nums);

  // print output
  for(auto subset: subsets){
    cout << "[";
    for(int i=0; i<subset.size(); i++){
      cout << subset[i];
      if(i != subset.size() - 1){
        cout << ",";
      }
    }
    cout << "]";
    cout << endl;
  }
  
  return 0;
}