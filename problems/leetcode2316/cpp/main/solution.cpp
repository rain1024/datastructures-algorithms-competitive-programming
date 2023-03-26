#include "solution.h"
#include "helpers.h"

#include <algorithm>
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

  int e;
  cin >> e;

  vector<vector<int>> edges(e, vector<int>(2));
  for (int i = 0; i < e; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> edges[i][j];
    }
  }

  Solution solution;
  int output = solution.countPairs(n, edges);

  // print output
  cout << output << endl;

  return 0;
}