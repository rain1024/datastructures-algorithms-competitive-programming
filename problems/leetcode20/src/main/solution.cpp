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
  string s;
  cin >> s;

  Solution solution;
  bool isValid = solution.isValid(s);

  // print output
  cout << isValid << endl;
  
  return 0;
}