// acmicpc 17219
// authored by jihwankim
// study
// 23-08-19 PM 07:45
#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> maps;

void solve() {
	cin >> n >> m;
	string site, pw;
	for(int i = 0 ; i<n; i++) {
		cin >> site >> pw;
		maps[site] = pw;
	}	
	for(int i = 0; i<m; i++) {
		cin >> site;
		cout << maps[site] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();
	return 0;
}
// PM 07:49
