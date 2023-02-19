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
  vector<string> input(n);
  for(int i = 0; i < n; i++){
    cin >> input[i];
  }

  Solution solution;
  vector<vector<string>> v = solution.groupAnagrams(input);

  // print output
  for(auto item: v){
    for(auto s: item){
      cout << s << " ";
    }
    cout << endl;
  }
  
  return 0;
}