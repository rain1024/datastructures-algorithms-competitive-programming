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
  vector<int> v;
  int i;
  while(n--){
    cin >> i;
    v.push_back(i);
  }

  Solution solution;
  bool output = solution.containsDuplicate(v);

  // print output
  cout << output << endl;
  
  return 0;
}