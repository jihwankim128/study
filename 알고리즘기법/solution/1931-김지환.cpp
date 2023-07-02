//acm 1931
//authored by jihwankim
//23-06-24 PM 11:46
#include <bits/stdc++.h>

using namespace std;

typedef struct of{
	int start;
	int end;
}of;

int n;
vector<of> ofs;

bool cmp(of &of1, of &of2) {
	if(of1.end == of2.end) {
		return of1.start < of2.start;
	}
	return of1.end < of2.end;
}

void input() {
	cin >> n;
	of v;
	for(int i = 0; i<n; i++) {
		cin >> v.start >> v.end;
		ofs.push_back(v);	
	}
	sort(ofs.begin(), ofs.end(), cmp);
} 

void solve() {
	int time = 0;
	int cnt = 0;
	for(int i = 0; i<ofs.size(); i++) {
		if(ofs[i].start < time) continue;
		time = ofs[i].end;
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

// AM 12 : 04
