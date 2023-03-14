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

  string line;
  int n = 0;
  set<string> names;

  int traffic = 0;


  while(getline(cin, line)){
    if(line[0] == '+'){
      names.insert(line.substr(1));
      n++;
    } else if (line[0] == '-'){
      names.erase(line.substr(1));
      n--;
    } else {
      // parse string with format name:message
      int i = line.find(':');
      string name = line.substr(0, i);
      string message = line.substr(i+1);
      traffic += message.size() * n;
    }    
  }

  cout << traffic << endl;
  
  return 0;
}