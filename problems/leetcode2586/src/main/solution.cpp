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

  vector<string> words(n);
  for(int i=0; i<n; i++){
    cin >> words[i];
  }

  int left, right;
  cin >> left >> right;

  Solution solution;
  int result = solution.vowelStrings(words, left, right);

  // print output
  cout << result << endl;
  
  return 0;
}