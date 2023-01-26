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
  int x;
  cin >> x;

  Solution solution;
  vector<int> v = solution.solve(x);

  // print output
  for(auto i: v){
    cout << i << endl;
  }
  
  return 0;
}