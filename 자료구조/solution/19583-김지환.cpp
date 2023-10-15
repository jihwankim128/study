// acmicpc 19583
// authored by jihwankim
// study
// 23-08-19 PM 08:36
#include <bits/stdc++.h>

using namespace std;

int s, e, q;
unordered_map<string, int> m;

void solve() {
	string ss, se, sq;
	cin >> ss >> se >> sq;
	ss = ss.substr(0,2) + ss.substr(3,2);
	se = se.substr(0,2) + se.substr(3,2);
	sq = sq.substr(0,2) + sq.substr(3,2);
	s = stoi(ss), e = stoi(se), q = stoi(sq);
	int cnt = 0;
	while(true) {
		string stime, name; 
		int time;
		cin >> stime >> name;
		if(cin.eof()) break;
		
		stime = stime.substr(0,2) + stime.substr(3,2);
		time = stoi(stime);
		if(time <= s && m.find(name) == m.end()) m[name] = 1;
		else if(time >= e && time <= q) {
			if(m[name] == 1) {
				cnt++;
				m[name]++;
			}
		}
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
// PM 08:54
