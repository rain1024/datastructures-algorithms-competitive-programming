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

  // get input 
  string start;
  string end;
  cin >> start >> end;

  char sx = start[0];
  char sy = start[1];
  char ex = end[0];
  char ey = end[1];
  int steps = 0;
  
  vector<string> moves;
  
  while(sx != ex || sy != ey){
    string move = "";
    string mx = "";
    string my = "";
    if(sx < ex){
      sx++;
      mx = "R";
    } else if(sx > ex){
      mx = "L";
      sx--;
    }
    if(sy < ey){
      sy++;
      my = "U";
    } else if (sy > ey){
      sy--;
      my = "D";
    }
    steps++;
    move += mx;
    move += my;
    moves.push_back(move);
  }
  // write output
  cout << steps << '\n';
  for(auto move : moves){
    cout << move << '\n';
  }
  return 0;
}