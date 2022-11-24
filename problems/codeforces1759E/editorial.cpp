#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int n;
int arr[MAXN];

int solve(int i, long long h, int s2, int s3) {
	if (i == n) return 0;
	if (arr[i] < h)
		return solve(i + 1, h + (arr[i] / 2), s2, s3) + 1;
	int ans1 = (s2 ? solve(i, h * 2, s2 - 1, s3) : 0);
	int ans2 = (s3 ? solve(i, h * 3, s2, s3 - 1) : 0);
	return max(ans1, ans2);
}

int main() {
	int t; cin >> t;
	while(t--) {
		long long h; cin >> n >> h;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n);
		cout << solve(0, h, 2, 1) << endl;
	}
}