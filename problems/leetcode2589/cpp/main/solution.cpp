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
  int n;
  cin >> n;

  vector<vector<int>> tasks(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
  }

  Solution solution;
  int output = solution.findMinimumTime(tasks);

  // print output
  cout << output << endl;

  return 0;
}