//acmicpc 2531
//authored by jihwankim
//23-07-14 PM 06:13
#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> s;
vector<pair<string,int> > v;
int k, l;

bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
	return p1.second < p2.second;
}

void input() {
	string sno;
	cin >> k >> l;
	for(int i = 0; i<l; i++) {
		cin >> sno;
		if(s.find(sno) != s.end()) s.erase(sno);
		s[sno] = i;
	}
}

void solve() {
	vector<pair<string, int>> v(s.begin(), s.end());
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i<min(k, (int)v.size()); i++) {
		cout << v[i].first << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

