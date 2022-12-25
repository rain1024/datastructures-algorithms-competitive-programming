#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

pair<string, string> split(string s, char delimiter) {
  pair<string, string> p;
  int n = s.length();
  int k = s.find(delimiter);
  p.first = s.substr(0, k);
  p.second = s.substr(k+1, n - k-1);
  return p;
}

struct Task {
  int v00;
  int v01;
  int v10;
  int v11;
};

Task parse(string line){
  auto [v0, v1] = split(line, ',');
  auto [_v00, _v01] = split(v0, '-');
  auto [_v10, _v11] = split(v1, '-');
  int v00 = stoi(_v00), v01 = stoi(_v01);
  int v10 = stoi(_v10), v11 = stoi(_v11);
  return Task { v00, v01, v10, v11};
}

int count_fully_contain(string line) {
  auto [v00, v01, v10, v11] = parse(line);
  if(((v00 - v10) * (v01 - v11)) <= 0){
    return 1;
  } else {
    return 0;
  }
}

int count_overlap(string line){
  auto [v00, v01, v10, v11] = parse(line);
  printf("(%d,%d) - (%d,%d)\n", v00, v01, v10, v11);
  if(((v00 - v11) * (v01 - v10)) <= 0){
    cout << 1 << endl;
    return 1;
  } else {
    cout << 0 << endl;
    return 0;
  }
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  int total_full_contain = 0;
  int total_overlap = 0;
  while (getline(f, line)) {
    if (line.size() != 0) {
      total_full_contain += count_fully_contain(line);
      total_overlap += count_overlap(line);
    }
  }
  cout << "Full Contain = " << total_full_contain << endl;
  cout << "Overlap = " << total_overlap << endl;
}