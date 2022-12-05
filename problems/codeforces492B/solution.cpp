// #include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  int d = 0;
  int a[n];

  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a, a+n);

  d = max(a[0], l-a[n-1]) * 2;
  for(int i=1; i<n; i++){
    d = max(d, a[i] - a[i-1]); 
  }
  
  cout.precision(20);
  cout << fixed << d / 2.0<< endl;
  return 0;
}