// acmicpc.net/problem/10807
// author : kimjihwan
// 2023-05-20 PM 2: 34 

#include <iostream>
#include <algorithm>

using namespace std;

int n, v;
int arr[202];

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int idx;
		cin >> idx;
		arr[idx+100]++;
	}
	cin >> v;
}

void solve() {
	cout << arr[v+100];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-20 PM 2:35
