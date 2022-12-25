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

string encrypt(long long num){
  char c;
  string s = "";
  map<int, string> m = {
    {0, "0"},
    {1, "1"},
    {2, "2"},
    {-1, "-"},
    {-2, "="}
  };
  while(num > 0){
    
  }
  
  
  cout << "value = " << value << endl;
  s = s + m[value];
  while(k > 0){
    num = num - value * pow(5, k);
    k--;
    cout << "k = " << k << ", num = " << num << endl;
   
    cout << "vf = " << vf << ", value = " << value << endl;
    s = s + m[value];
  }
  return s;
}

long long decrypt(string line){
  int n = line.size();
  long long num = 0;
  map<char, int> m = {
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'-', -1},
    {'=', -2},
  };
  for(int i=0; i<n; i++){
    num += m[line[i]] * pow(5, n-1-i);
  }
  cout << num << endl;
  return num;
}
int main(int argc, char* argv[]){
  string input = argv[1];
  string line;
  fstream f(input);
  long long result = 0;
  // while(getline(f, line)){
  //   if(line.size() != 0){
  //     cout << line << endl;
  //     result += decrypt(line);
  //   }
  // }
  // cout << "result = " << result << endl;
  // string s = encrypt(result);
  string s = encrypt(4890);
  cout << "decrypt = " << s << endl;
}