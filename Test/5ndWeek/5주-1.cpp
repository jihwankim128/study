#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int sum = INT_MAX;
	int x, y;
	for(int i = 0; i<n-1; i++) {
		int v = lower_bound(arr+i+1, arr+n, -arr[i]) - arr;
		
		if(abs(sum) > abs(arr[i] + arr[v]) && (arr[v] != 0 && i!=v)){
			x = i; y = v;
			sum = arr[i] + arr[v];
		}
		if(abs(sum) > abs(arr[i] + arr[v-1]) && (arr[v-1] != 0 && i!=(v-1))) {
			x = i; y = v-1;
			sum = arr[i] + arr[v-1];
		}
	}
	cout << min(arr[x],arr[y]) << " " << max(arr[x], arr[y]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
