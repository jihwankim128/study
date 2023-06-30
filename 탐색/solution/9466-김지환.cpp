// acmicpc.net/problem/9466
// authored by kimjihwan
// 2023-06-09 PM 03:01 

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std; 

int n, t;
int stu[100001];
bool cycleChk[100001];
bool visited[100001];

void input() {
	cin >> n;
	for(int i = 1; i<=n; i++) {
		cin >> stu[i];
		cycleChk[i] = visited[i] = false;
	}	
}

bool cycle(int x) {
	queue<int> q;
	q.push(stu[x]);
	visited[x] = true;
	vector<int> cycles;
	cycles.push_back(x);
	
	while(!q.empty()) {
		int v = q.front(); q.pop();
		cycles.push_back(v);
		if(cycleChk[v]) return false;
		if(visited[v]) {
			if(v == x) {
				for(int i = 0; i<cycles.size(); i++) {
					cycleChk[cycles[i]] = true;
				}
				return true;
			}
			continue;
		}
		visited[v] = true;
		q.push(stu[v]);
	}
	return false;
}

void solve() {
	int cnt = 0;
	for(int i = 1; i<=n; i++) {
		if(cycleChk[i]) {
			cnt++;
			continue;
		}
		if(cycle(i)) {
			cnt++;
		}
		else cycleChk[i] = true;
	}
	cout << n - cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> t;
	while(t--) {
		input();
		solve();
	}
	
	return 0;
}
