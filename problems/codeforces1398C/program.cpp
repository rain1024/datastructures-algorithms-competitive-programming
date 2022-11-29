#include <bits/stdc++.h>
#include <vector>
#include <map>
 
#define ll long long int
using namespace std;


void count(vector<int> a){
  ll output = 0;
  map<int, int> m;
  m[0]++;
  int n = (int) a.size();
  ll sum = 0;
  for(int i=0; i<n; i++){
    sum += a[i] - 1;
    output += m[sum];
    m[sum]++;
  }
  cout << output << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for(auto&x : a){
        char c;
        cin >> c;
        x = (int) c - '0';
    }
    count(a);
  }
  return 0;
}