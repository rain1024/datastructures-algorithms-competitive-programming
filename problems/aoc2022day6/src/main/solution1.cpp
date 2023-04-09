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

int main(int argc, char* argv[]) {
  string input = argv[1];
  fstream f(input);
  string line;
  int result = 0;
  getline(f, line);
  set<char> s;
  s.insert(line[0]);
  s.insert(line[1]);
  s.insert(line[2]);
  int n = (int) line.size();
  int D; // distinct characters
  D = 4; 
  D = 14;
  for (auto i = D-1; i < n; i++) {
    set<char> se;
    for(int k=0; k<D; k++){
      se.insert(line[i-k]);
    }
    if((int) se.size() == D){
      result = i + 1;
      break;
    }
  }
  cout << endl;
  cout << "result = " << result << endl;
}