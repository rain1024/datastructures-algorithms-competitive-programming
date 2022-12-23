#include <iostream>
#include <algorithm>

using namespace std;

#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L

using namespace std;

#define max_m 200000
#define small 450

int cycle[small][small];
int manual[max_m]{0};
int record[max_m + 1];
int x[max_m + 1];
int y[max_m + 1];

struct Solution {
  void run() {
    int n, x;
    cin >> n >> x;
    int a[n];
    int order[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      order[i] = a[i];
    }
    sort(order, order + n);

    for (int i = 0; i < n; i++) {
      if (order[i] == a[i]) {
        continue;
      }

      if (i < x && n - 1 - i < x) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  Solution solution = Solution();

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solution.run();
  }
  return 0;
}