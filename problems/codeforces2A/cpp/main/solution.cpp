#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
// #include <fstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // bool is_use_file = false;

  // filesystem::path filepath =
  //     filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  // ifstream file(filepath);

  // if (is_use_file) {
  //   cin.rdbuf(file.rdbuf());  // redirect cin to file
  // }

  int tt;
  cin >> tt;
  unordered_map<string, int> scores;
  vector<pair<string, int>> rounds;

  string name;
  int score;

  while (tt--) {
    cin >> name;
    cin >> score;
    rounds.push_back({name, score});
    if (scores.find(name) == scores.end()) {
      scores[name] = score;
    } else {
      scores[name] += score;
    }
  }

  int max_score = INT_MIN;
  for (auto it : scores) {
    if (it.second > max_score) {
      max_score = it.second;
    }
  }

  string winner = "";

  // for(auto it: scores){
  //   cout << it.first << " " << it.second << endl;
  // }

  set<string> winners;

  for (auto it : scores) {
    if (it.second == max_score) {
      winners.insert(it.first);
    }
  }

  unordered_map<string, int> first_scores;

  for(auto it: rounds){
    if(winners.find(it.first) != winners.end()){
      first_scores[it.first] += it.second;
      if(first_scores[it.first] >= max_score){
        winner = it.first;
        break;
      }
    }
  }

  cout << winner << endl;

  return 0;
}