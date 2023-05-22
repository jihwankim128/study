// acmicpc.net/problem/2493
// ž 
// author : kimjihwan
// 2023-05-22 PM 05:05

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[500005];
stack<pair<int, int> > tx;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	tx.push({1e8, 0});
	for(int i = 0; i<n; i++) {
		int rx = arr[i];
		while(!tx.empty() && tx.top().first < rx) tx.pop();
		
		cout << tx.top().second << " ";
		
		tx.push({rx, i+1});
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-22 PM 05:40
