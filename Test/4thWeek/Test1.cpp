//4th test
//23-07-07 PM 06:23
//authored by jihwankim

#include <bits/stdc++.h>

using namespace std;

int n;
int blos = 301;
int fall = 1201;
vector<pair<int, int> > flo;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		flo.push_back({a*100+b, c*100+d});
	}
	sort(flo.begin(), flo.end());
}

void solve() {
	int time = blos;
	int cnt = 0;
	int idx = 0;
	while(time < fall) {
		int maxTime = time;
		for(int i = 0; i<flo.size(); i++) {
			if(flo[i].first <= time && flo[i].second > maxTime) {
				maxTime = flo[i].second;
			}
		}
		if(time == maxTime) {
			cnt = 0;
			break;
		}
		time = maxTime;
		cnt++;
	}
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

//PM 07:01
