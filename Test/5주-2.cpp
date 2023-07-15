//예은문제
#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> s;

void input() {
	cin >> n >> m;
	string id, pw;
	for(int i = 0; i<n; i++) {
		cin >> id >> pw;
		s[id] = pw;
	}
}

void solve() {
	string id;
	for(int i = 0 ; i<m; i++) {
		cin >> id;
		cout << s[id] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
