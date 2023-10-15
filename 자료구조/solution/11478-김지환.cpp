// acmicpc 11478
// authored by jihwankim
// study
// 23-08-19 PM 08:17
#include <bits/stdc++.h>

using namespace std;

string s;
unordered_set<string> m;

void solve() {
	cin >> s;
	for(int i = 0; i<s.size(); i++) {
		string s2 = s.substr(i, 1);
		m.insert(s2);
		for(int j = 0; j < i; j++) {
			s2 = s.substr(j, i-j+1);
			m.insert(s2);
		} 
	}
	cout << m.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
// PM 08:32
