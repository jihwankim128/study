//acmicpc 11659
//authored by jihwankim
//23-07-06 PM 09:41

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];

void input() {
	cin >> n >> m;
	for(int i = 1; i<=n; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
}

void solve() {
	for(int i = 0; i<m; i++){
		int a, b;
		cin >> a >> b;
		cout << arr[b]-arr[a-1] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

//PM 09:49
