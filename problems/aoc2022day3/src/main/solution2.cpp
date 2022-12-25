#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iterator>

template <class T, class CMP = std::less<T>, class ALLOC = std::allocator<T> >
std::set<T, CMP, ALLOC> operator * (
  const std::set<T, CMP, ALLOC> &s1, const std::set<T, CMP, ALLOC> &s2)
{
  std::set<T, CMP, ALLOC> s;
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
    std::inserter(s, s.begin()));
  return s;
}

using namespace std;

int get_priority(char c) {
  int priority;
  // get priority
  if (c >= 'A' && c <= 'Z') {
    priority = c - 'A' + 27;
  }
  if (c >= 'a' && c <= 'z') {
    priority = c - 'a' + 1;
  }
  return priority;
}

char find_badges(vector<set<char>> groups){
  set<char> s = groups[0] * groups[1] * groups[2];
  char c = *s.begin();
  return c;
}

int main(int argc, char* argv[]) {
  string input = argv[1];
  string line;
  fstream f(input);

  int sum = 0;
  int count = 0;
  vector<set<char>> groups;
  while (getline(f, line)) {
    count += 1;
    set<char> s1;
    if (line.size() != 0) {
      count += 1;
      int n = line.size();
      for (int i = 0; i < n; i++) {
        s1.insert(line[i]);
      }
      groups.push_back(s1);
      if(count % 3 == 0){
        int badge = find_badges(groups);
        sum += get_priority(badge);
        groups.clear();
        count = 0;
      }
    }
  }
  cout << "Sum = " << sum << endl;
}