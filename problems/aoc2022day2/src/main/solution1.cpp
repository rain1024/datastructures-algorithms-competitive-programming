#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);
  string s;
  int score1 = 0;
  int score2 = 0;
  map<char, int> m1 = {{'X', 1}, {'Y', 2}, {'Z', 3}};
  // B       A      C          B
  // Paper > Rock > Scissors > Paper
  // Y       X      Z          Y
  map<pair<char, char>, int> m2 = {
      {make_pair('A', 'X'), 3}, {make_pair('A', 'Y'), 6},
      {make_pair('A', 'Z'), 0}, {make_pair('B', 'X'), 0},
      {make_pair('B', 'Y'), 3}, {make_pair('B', 'Z'), 6},
      {make_pair('C', 'X'), 6}, {make_pair('C', 'Y'), 0},
      {make_pair('C', 'Z'), 3}};

  map<char, int> m3 = {{'X', 0}, {'Y', 3}, {'Z', 6}};
  map<pair<char, char>, char> m4 = {
      {make_pair('A', 'X'), 'Z'}, {make_pair('A', 'Y'), 'X'},
      {make_pair('A', 'Z'), 'Y'}, {make_pair('B', 'X'), 'X'},
      {make_pair('B', 'Y'), 'Y'}, {make_pair('B', 'Z'), 'Z'},
      {make_pair('C', 'X'), 'Y'}, {make_pair('C', 'Y'), 'Z'},
      {make_pair('C', 'Z'), 'X'}};

  while (getline(f, line)) {
    if (line.size() != 0) {
      score1 += m1[line[2]] + m2[make_pair(line[0], line[2])];
      char my_choice = m4[make_pair(line[0], line[2])];
      score2 += m1[my_choice] + m3[line[2]];
    }
  }
  cout << "Score 1 = " << score1 << endl;
  cout << "Score 2 = " << score2 << endl;
}