//acm 11399
//authored by jihwankim
//23-06-25 AM 02:57
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1005];

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
} 

void solve() {
	int time = 0;
	int late = 0;
	for(int i = 0 ; i<n; i++) {
		time += late+arr[i];
		late += arr[i];
	}
	cout << time;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

// AM 03: 06
