#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  int n, a, b;
  cin >> t;
  while(t--) {
    cin >> n >> a >> b;
    if(n == a && a == b){
        cout << "Yes\n";
      continue;
    }
    if(n > a + b + 1){
      cout << "Yes\n";
      continue;
    } 
    cout << "No\n";
  }
  return 0;
}