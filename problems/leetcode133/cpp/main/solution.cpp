#include "solution.h"
#include "helpers.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  bool is_use_file = false;

  filesystem::path filepath =
      filesystem::current_path().parent_path().parent_path() / "data" / "1.in";
  ifstream file(filepath);

  if (is_use_file) {
    cin.rdbuf(file.rdbuf());  // redirect cin to file
  }

  // get input
  int n;
  cin >> n;
  if(n == 0){
    return 0;
  }

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }

  string s;
  getline(cin, s);
  map<int, Node*> m;
  for(int i=0; i<n; i++){
    Node* n = new Node(i+1);
    m[i+1] = n;
  }

  for(int i=0; i<n; i++){
    getline(cin, s);
    cout << "string s = " << s << endl;
    vector<string> v = parse_line(s);
    vector<int> nums;
    for(auto item: v){
      cout << item << " ";
      nums.push_back(stoi(item));
      m[i+1]->neighbors.push_back(m[stoi(item)]);
    }
    cout << endl;
  }

  Solution solution;
  Node* result = solution.cloneGraph(m[1]);

  cout<< result->val << endl;

  return 0;
}