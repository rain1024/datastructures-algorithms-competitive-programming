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
  vector<int> numbers(x);
  for(int i=0; i<x; i++){
    cin >> numbers[i];
  }
  int target;
  cin >> target;

  Solution solution;
  vector<int> output = solution.twoSum(numbers, target);

  // print output
  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}