#include "solution.h"
#include "helpers.h"

#include <cmath>

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>


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
  int n;
  cin >> n;

  int r;
  cin >> r;
  vector<vector<int>> roads(r, vector<int>(3));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> roads[i][j];
    }
  }

  Solution solution;
  int output = solution.minScore(n, roads);

  // print output
  cout << output << endl;

  return 0;
}