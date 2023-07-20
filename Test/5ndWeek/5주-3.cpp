//효원문제
#include <bits/stdc++.h>

using namespace std;

int n, m;
unordered_map<string, string> s;

bool cmp(pair<string,string> &a, pair<string, string> &b) {
	return a.first > b.first;
}
void input() {
	cin >> n;
	string name, status;
	for(int i = 0; i<n; i++) {
		cin >> name >> status;
		s[name] = status;
	}
}

void solve() {
	vector<pair<string, string> > v(s.begin(), s.end());
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i<v.size(); i++) {
		if(v[i].second == "enter") {
			cout << v[i].first << "\n";
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
