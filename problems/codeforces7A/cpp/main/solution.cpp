#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
// #include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file
  string s;
  string w = "";
  int count = 0;
  while(getline(cin, s)){
    if(s == "BBBBBBBB"){
      count++;
    } else {
      w = s;
    }
  }
  if(count < 8){
    for(auto c: w){
      if(c == 'B'){
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}