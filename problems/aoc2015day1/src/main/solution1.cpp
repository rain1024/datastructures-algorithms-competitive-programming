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

pair<int, int> solve(string s){
  int f = 0; // floor
  int p = -1; // position
  for(int i=0; i<s.size(); i++){
    if(s[i] == '('){
      f++;
    } else {
      f--;
    }
    if(f == -1 && p == -1){
      p = i + 1;
    }
  }
  return make_pair(f, p);
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  getline(f, line);
  f.close();
  auto [finalFloor, firstBasementEntry] = solve(line);
  cout << "finalFloor = " << finalFloor << endl;
  cout << "firstBasementEntry = " << firstBasementEntry << endl;
  return 0;
}