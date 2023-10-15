// acmicpc 2252
// authored by jihwankim
// study
// 23-08-13 PM 08:09
#include <bits/stdc++.h>

using namespace std;

vector<int> arr[32005];
int indeg[32005];
int n, m;

void input() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		indeg[b]++;
	}
}

void solve() {
	queue<int> q;
	for(int i = 1; i<=n; i++) {
		if(indeg[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int e = 0; e < arr[v].size(); e++) {
			indeg[arr[v][e]]--;
			if(indeg[arr[v][e]] == 0) q.push(arr[v][e]);
		}
		cout << v << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// PM 08:15 
