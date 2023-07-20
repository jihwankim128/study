//범조 문제 failed
include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];

void input() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
}

bool vaild(int v) {
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		if(arr[i] >= m) cnt++;
	}
	return cnt >= m;
}

void solve() {
	int s = 0; 
	int e = 1e9;
	int mid;
	while(s <= e) {
		mid = (s+e)/2;
		if(vaild(mid)) {
			e = m-1;
		}
		else s = m+1;
	}
	cout << e;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
