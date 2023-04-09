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

  string colors;
  cin >> colors;

  int m;
  cin >> m;

  vector<vector<int>> edges(m, vector<int>(2));
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  Solution solution;
  int output = solution.largestPathValue(colors, edges);


  // print output
  cout << output << endl;

  return 0;
}