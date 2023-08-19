// acmicpc 9375
// authored by jihwankim
// study
// 23-08-19 PM 07:52
#include <bits/stdc++.h>

using namespace std;

int t;

void solve(unordered_map<string, int> &m) {
	int cnt = 1;
	for(auto &x : m) {
		cnt *= x.second;
	}
	cout << cnt-1 << "\n";
}

void input() {
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		unordered_map<string, int> m;
		for(int i = 0; i<n; i++) {
			string type;
			cin >> type >> type;
			if(m.find(type) != m.end()) {
				m[type]++;
			}
			else m[type] = 2;
		}
		solve(m);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	
	return 0;
}
// PM 07:58 
