//acmicpc 12852
//authored by jihwankim
//23-07-04 AM 01:09

#include <bits/stdc++.h>

using namespace std;

int n;
int d[1000001];

void input() {
	cin >> n;
	
	for(int i = 2; i<=n; i++) {
		int minNum = INT_MAX;
		if(i%3 == 0) minNum = d[i/3] + 1;
		if(i%2 == 0) minNum = min(minNum, d[i/2]+1);
		minNum = min(minNum, d[i-1]+1);
		d[i] = minNum; 
	}
}

void back(int v) {
	cout << v << " ";
	if(v == 1) return;
	int minV = INT_MAX;
	int nextV = 1;
	if(v%2 == 0) {
		if(minV > d[v/2]) {
			nextV = v/2;
			minV = d[v/2];
		}
	}
	if(v%3 == 0) {
		if(minV > d[v/3]) {
			nextV = v/3;
			minV = d[v/3];
		}
	}
	if(minV > d[v-1]) {
		nextV = v-1;
	}
	back(nextV);
}

void solve() {
	cout << d[n] << "\n";
	back(n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
} 

//AM 01:18
