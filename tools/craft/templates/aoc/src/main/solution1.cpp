#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <set>

using namespace std;

int main(int argc, char* argv[]){
  string input = argv[1];
  string line;
  fstream f(input);
  int result = 0;
  while(getline(f, line)){
    if(line.size() != 0){
      cout << line << endl;
    }
  }
  cout << "result = " << result << endl;
}