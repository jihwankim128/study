//acm 1026
//authored by jihwankim
//23-06-25 AM 12:23
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[55];
int brr[55]; 

bool cmp(int &a, int &b) {
	return a > b;
}

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) cin >> arr[i];
	for(int i = 0; i<n; i++) cin >> brr[i];
	sort(brr, brr+n);
	sort(arr, arr+n, cmp);
} 

void solve() {
	int ans = 0;
	for(int i = 0 ; i<n; i++) {
		ans += (arr[i] * brr[i]);
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

// AM 12 : 29
