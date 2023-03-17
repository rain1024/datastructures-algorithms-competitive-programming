#include "solution.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // get input
  int x;
  cin >> x;

  vector<int> v(x);
  for(int i=0; i<x; i++){
    cin >> v[i];
  }

  Solution solution;
  vector<vector<int>> output = solution.threeSum(v);

  // print output
  for(int i=0; i<output.size(); i++){
    for(int j=0; j<output[i].size(); j++){
      cout << output[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}