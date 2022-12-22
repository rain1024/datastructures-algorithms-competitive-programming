#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  int x = 0;
  cin >> tt;
  string s;
  while(tt--){
    cin >> s;
    if(s[1] == '+'){
      x++;
    } else {
      x--;
    }
  }
  cout << x << endl;
  return 0;
}