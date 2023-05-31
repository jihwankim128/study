// acmicpc.net/problem/1697
// authored by kimjihwan
// 2023-05-31 PM 04:36

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100001];

void input() {
	cin >> n >> m;
	arr[n] = 1;
}

void bfs() {
	queue<int> q;
	q.push(n);
	
	while(!q.empty()) {
		int v = q.front(); q.pop();
		int v1 = v+1;
		int v2 = v*2;
		int v3 = v-1;
		if(v1<=100000 && arr[v1] == 0) {
			arr[v1] = arr[v]+1;
			q.push(v1);
		}
		if(v2<=100000 && arr[v2] == 0) {
			arr[v2] = arr[v]+1;
			q.push(v2);
		}
		if(v3 >= 0 && arr[v3] == 0) {
			arr[v3] = arr[v]+1;
			q.push(v3);
		}
	//	cout << "arr[" << v <<"] 일 때, arr[" << v1 << ", " << v2 <<"] = ";
	//	cout << arr[v] << ", " << arr[v1] << ", " << arr[v2] << "\n"; 
	}	
}

void solve() {
	bfs();
	cout << arr[m]-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
//PM 5:00
