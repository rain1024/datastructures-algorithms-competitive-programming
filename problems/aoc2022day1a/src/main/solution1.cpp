#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[]){
  string input = argv[1];
  string line;
  fstream f(input);
  long long max_c = 0;
  long long sum_c = 0;
  while(getline(f, line)){
    if(line.size() == 0){
      max_c = max(max_c, sum_c);
      sum_c = 0;
    } else {
      sum_c += stoi(line);
    }
  }
  cout << "max_c = " << max_c << endl;
}