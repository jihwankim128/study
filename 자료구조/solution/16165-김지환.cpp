// acm 16165
// authored by jihwankim
// study
// 23-08-19 PM 08:00
#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> girlGroup;

void input() {
	cin >> n >> m;
	string team, member;
	int memberCnt;
	for(int i = 0; i<n; i++) {
		cin >> team >> memberCnt;
		for(int j = 0; j<memberCnt; j++) {
			cin >> member;
			girlGroup[member] = team;
		}
	}
}

void solve() {
	string teamOrMember; int type;
	for(int i = 0; i<m; i++) {
		cin >> teamOrMember >> type;
		if(type == 1) cout << girlGroup[teamOrMember] << "\n";
		else {
			for(auto &x : girlGroup) {
				if(x.second == teamOrMember) {
					cout << x.first << "\n";
				}
			}
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

// PM 08:12 
