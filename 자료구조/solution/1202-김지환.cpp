//acmicpc 1202
//authored by jihwankim
//23-07-21 AM 04:13

#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> gem[300005];
multiset<int> bag;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	if(p1.second == p2.second) {
		return p1.first > p2.first;
	}
	return p1.second > p2.second;
}
void input() {
	cin >> n >> k;
	for(int i = 0; i<n; i++) {
		int m, v;
		cin >> gem[i].first >> gem[i].second;
	}
	sort(gem, gem+n, cmp);
	
	for(int i = 0; i<k; i++) {
		int w;
		cin >> w;
		bag.insert(w);
	}
}

void solve() {
	long long sum = 0;
	
	for(int i = 0; i<n; i++) {
		auto it = bag.lower_bound(gem[i].first);
		if(it == bag.end()) continue;
		sum += gem[i].second;
		bag.erase(it);
	}
	cout << sum;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

