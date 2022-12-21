#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

int const MAX_N = 50;

int solve(int* a, int n){
  int s;
  int m = INT_MAX;
  int k;

  for(int i=0; i<n; i++){
    s += a[i];
    k = a[i];
    bool eveness = (k % 2 == 0);
    int mk = 0;
    bool result = eveness;
    while(result == eveness){
      k /= 2;
      result = (k % 2 == 0);
      mk++;
    } 
    m = min(m, mk);
  }

  if(s % 2 == 0){
    return 0;
  } else {
    return m;
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  int n;
  int a[MAX_N];
  cin >> tt;
  while(tt--){
    cin >> n;
    for(int i=0; i<n; i++){
      cin >> a[i];
    }
    cout << solve(a, n) << endl;
  }
  return 0;
}