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
  char c;
  vector<vector<char>> inputs;
  for(int i=0; i<9; i++){
    vector<char> row;
    for(int j=0; j<9; j++){
      cin >> c;
      row.push_back(c);
    }
    inputs.push_back(row);
  }

  Solution solution;
  bool output = solution.isValidSudoku(inputs);

  // print output
  cout << output << endl;

  return 0;
}