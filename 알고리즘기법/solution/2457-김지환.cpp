//acm 2457
//authored by jihwankim
//23-06-25 AM 03:07
#include <bits/stdc++.h>
#define b first
#define f second

using namespace std;

int n;
int calday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days[13];
int blossom, fall;
vector<pair<int, int> > flowers;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
	if(p1.f == p2.f) {
		return p1.b > p2.b;
	}
	return p1.f < p2.f;
}

void input() {
	cin >> n;
	int month, day;
	int s, e;
	
	for(int i = 2; i<=12; i++) {
		days[i] = days[i-1] + calday[i-1];	
	}
	
	blossom = days[3] + 1;
	fall = days[11] + 30;
	
	for(int i =0 ; i<n; i++) {
		cin >> month >> day;
		s = days[month] + day;
		cin >> month >> day;
		e = days[month] + day;
		flowers.push_back({s, e});
	}
	sort(flowers.begin(), flowers.end(), cmp);
} 

bool valid(pair<int, int> &p) {
	return p.b < blossom & p.f < blossom;
	return p.b > fall & p.f > fall;
	return false;
}

void solve() {
	int time = 0;
	int cnt = 1;
	for(int i = 0; i < flowers.size(); i++) {
		if(valid(flowers[i])) continue;
		if(flowers[i].b < time) continue;
		time = flowers[i].f;
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

// AM 03: 06
