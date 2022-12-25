#include <algorithm>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int tt;
  int n;
  cin >> tt;
  int max_n;
  for (int ti = 0; ti < tt; ti++) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = 0;
    while(i < n && j < n){
      if(a[j] >= i+1){
        i++;
        j++;
      } else {
        j++;
      }
    }
    cout << "Case #" << ti + 1 << ": " << i << endl;
  }
}