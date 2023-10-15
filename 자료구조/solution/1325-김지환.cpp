// acmicpc 1325
// authored by jihwankim
// 23-08-19 AM 05:02
// study

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr[10005];
bool visited[10005];

void input() {
	cin >> n >> m;
	for(int i = 0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);		
	}
}

void solve() {
	queue<int> q;
	vector<int> computer;
	int maxCnt = 0;
	for(int i = 1; i<=n; i++) {
		fill(visited, visited+10005, false);
		q.push(i);
		visited[i] = true;
		int cnt = 0;
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int x : arr[v]) {
				if(visited[x]) continue;
				visited[x] = true;
				cnt++;
				q.push(x);
			}
		}
		if(maxCnt < cnt) {
			computer.clear();
			computer.push_back(i);
			maxCnt = cnt;
		}
		else if(maxCnt == cnt) computer.push_back(i);
	}
	sort(computer.begin(), computer.end());
	for(int x : computer) cout << x << " ";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 05: 10
