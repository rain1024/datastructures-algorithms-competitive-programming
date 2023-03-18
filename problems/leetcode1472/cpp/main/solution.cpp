#include "solution.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

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

  // get input and print output
  BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
  browserHistory->visit("google.com");
  browserHistory->visit("facebook.com");
  browserHistory->visit("youtube.com");
  cout << browserHistory->back(1) << endl;
  cout << browserHistory->forward(1) << endl;
  browserHistory->visit("linkedin.com"); 
  cout << browserHistory->forward(2) << endl; 
  cout << browserHistory->back(2) << endl;
  cout << browserHistory->back(7) << endl;
  
  return 0;
}