//acm 9466
//authored by jihwankim
// 06-14 AM 03:14

#include <bits/stdc++.h>

using namespace std;

int n;
int stu[100001];
bool visited[100001];
bool cycleChk[100001];

void input() {
	cin >> n;
	for(int i = 1; i<=n; i++) {
		cin >> stu[i];
		cycleChk[i] = false;
	}
}

bool cycle(int num) {
	queue<int> q;
	for(int i = 1; i<=n; i++) {
		visited[i] = false;
	}
	q.push(num);
	visited[num] = true;
	
	while(!q.empty()) {
		int x = stu[q.front()];
		q.pop();
		if(cycleChk[x] == true) return false;
		if(visited[x]) {
			if(x == num) return true;
			continue;
		}
		visited[x] = true;
		q.push(x);
	}
	
	return false;
}

void solve() {
	int cnt = 0;
	for(int i = 1; i<=n; i++) {
		if(cycle(i)) {
			cnt++;
		}
		else {
			cycleChk[i] = true;
		}
	}
	cout << n-cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--) {
		input();
		solve();
	}
	
	return 0;
}
