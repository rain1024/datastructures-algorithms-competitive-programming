#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 200;
bool visited[MAX_N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, w(0);
  cin >> n >> m;
  while(n != m){
    if (m > n){
      if(m % 2 == 0){
        m /= 2;
        w++;
      } else {
        m++,
        w++;
      }
    } else if(n > m){
      m++, w++;
    }
  }
  cout << w << endl;
  return 0;
}