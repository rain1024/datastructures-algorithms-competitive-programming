#include <bits/stdc++.h>
#include <vector>

using namespace std;

int dp(vector<int> v, long long h, int blues, int green, int count){
  if(v.empty()){
    return count;
  }
  if(blues < 0 || green < 0){
    return count;
  }

  while(h > v.back()){
    int hi = v.back();
    v.pop_back();
    h = h + hi/2;
    count++;
    if(v.empty()){
      return count;
    }
  }
  return max(dp(v, h * 2, blues - 1, green, count), dp(v, h * 3, blues, green - 1, count));
}

int solve(vector<int> v, long long h){
  return dp(v, h, 2, 1, 0);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  int n;
  long long h;
  
  while(tt--){
    cin >> n >> h;
    vector<int> v;
    while(n--){
      int p;
      cin >> p;
      v.push_back(p);
    }
    sort(v.begin(), v.end(), greater<int>());
    // for(auto i: v){
    //   cout << i << ' ';
    // }
    // cout << '\n';
    cout << solve(v, h) << '\n';
  }
  return 0;
}