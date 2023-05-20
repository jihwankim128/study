// acmicpc.net/problem/1457
// author : kimjihwan
// 2023-05-21 am 01:54

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
vector<pair<string, string> > s;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		s.push_back({s1, s2});
	}
}

void solve() {
	for(int i = 0; i<s.size(); i++) {
		sort(s[i].first.begin(), s[i].first.end());
		sort(s[i].second.begin(), s[i].second.end());
		if(s[i].first.compare(s[i].second) == 0) {
			cout << "Possible\n";
		}
		else cout << "Impossible\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-21 AM 02:02
