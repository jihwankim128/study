// acmicpc.net/problem/1457
// author : kimjihwan
// 2023-05-20 13:51

#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[100001];

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) cin >> arr[i];
	cin >> x;
	sort(arr, arr+n);
}

void solve() {
	int l = 0, r = n-1;
	int cnt = 0;
	while(l < r){
		if(arr[l]+arr[r] == x) cnt++;
		if(arr[l]+arr[r] > x) r--;
		else l++;
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-20 PM 1:55
