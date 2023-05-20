// acmicpc.net/problem/1457
// author : kimjihwan
// 2023-05-20 13:35

#include <iostream>
#include <cmath>

using namespace std;

int n;
int arr[10];

void input() {
	cin >> n;
}
void solve() {
	while(n) {
		arr[n%10]++;
		n/=10;
	}
	
	int cnt = 0;
	
	if(arr[6] > arr[9]) {
		int diff = abs(arr[6]-arr[9]);
		diff = diff/2 + diff%2;
		arr[6] = arr[9] + diff;
	}
	else {
		int diff = arr[9]-arr[6];
		diff = diff/2 + diff%2;
		arr[9] = arr[6] + diff;
	}
	
	for(int i = 0; i<10; i++) {
		cnt = max(cnt, arr[i]);
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
// 2023-05-20 PM 1:44
