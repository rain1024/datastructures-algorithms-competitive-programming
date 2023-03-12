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

  vector<int> v(x);

  for(int i=0; i<x; i++){
    cin >> v[i];
  }

  Solution solution;
  int result = solution.maxScore(v);

  // print output
  cout << result << endl;
  
  return 0;
}