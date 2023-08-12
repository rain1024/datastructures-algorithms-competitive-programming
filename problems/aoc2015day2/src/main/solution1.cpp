#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "helpers.h"

using namespace std;

pair<int, int> solve(vector<string> lines) {
  int s = 0; // square feet of wrapping paper
  int n = 0; // feet of ribbon
  int l, w, h;

  for(string line: lines){
    sscanf(line.c_str(), "%dx%dx%d", &l, &w, &h);
    s += 2*l*w + 2*w*h + 2*h*l + min({l*w, w*h, h*l});
    n += 2*min({l+w, w+h, h+l}) + l*w*h;
  }
  return make_pair(s, n);
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  vector<string> lines;
  while (getline(f, line)) {
    if (line.size() != 0) {
      lines.push_back(line);
    }
  }
  auto [s, n] = solve(lines);
  cout << "square feet of wrapping paper = " << s << endl;
  cout << "              feet of ribbon  = " << n << endl;
}