#include <bits/stdc++.h>
#include <cmath>
#include <vector>
 
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  int num_evens = 0;
  int odd_index = 0;
  int even_index =0;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i] % 2 == 0){
      num_evens++;
      even_index = i+1;
    } else {
      odd_index = i+1;
    }
  }
  int index = num_evens == 1 ? even_index : odd_index;
  cout << index << endl;
  return 0;
}