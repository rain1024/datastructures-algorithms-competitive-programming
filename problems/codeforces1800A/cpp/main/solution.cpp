#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstring>
// #include <fstream>

using namespace std;

string is_cat(string s){
  // cout << s << endl;
  if(s.size() < 4){
    return "NO";
  }
  for(int i=0; i<s.size(); i++){
    s[i] = tolower(s[i]);
  }

  // cout << s << endl;

  string s1 = "";
  s1 += s[0];
  for(int i=1; i<s.size(); i++){
    if(s[i] == s[i-1]){
      continue;
    } else{
      s1 += s[i];
    }
  }

  if(s1 == "meow"){
    return "YES";
  } else{
    return "NO";
  }
}
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" /
  //     "1.in";
  // ifstream file(filepath);
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file

  int tt;
  cin >> tt;
  int n;
  string s;
  while (tt--) {
    cin >> n;
    cin >> s;
    cout << is_cat(s) << endl;
  }
  return 0;
}