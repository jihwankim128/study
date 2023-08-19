//acmicpc 3151
//authored by jihwankim
//23-07-22 AM 04:00

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10005];

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
}

int upper_bounds(int s, int e, int key) {
	int findKey = n;
	while(s<=e) {
		int mid = (s+e)/2;
		int val = arr[mid];
		if(val > key) {
			e = mid - 1;
			findKey = mid;
		}
		else {
			s = mid + 1;
		}
	}
	return findKey;
}
int lower_bounds(int s, int e, int key) {
	int findKey = n;
	while(s<=e) {
		int mid = (s+e)/2;
		int val = arr[mid];
		if(val >= key) {
			e = mid-1;
			findKey = mid;
		}
		else {
			s = mid+1;
		}
	}
	return findKey;
}

void solve() {
	long long cnt = 0;
	//-6 -5 -4 -4 0 1 2 2 3 7
	for(int i = 0; i < n-2; i++) {
		for(int j = i+1; j<n-1; j++) {
			int key = arr[i]+arr[j];
			int s = lower_bounds(j+1, n, -key);
			int e = upper_bounds(j+1, n, -key);
			int sum = key + arr[s];
			if(sum == 0 && s < n) {
				cnt += e-s;
			}
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	//freopen("input.txt", "r", stdin);
	input();
	solve();
	
	return 0;
}
//AM 04:23
