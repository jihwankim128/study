// acmicpc 1992
// authored by jihwankim
// study
// 23-08-24 PM 05:24

#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v(65);

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> v[i];
	}
}

void solve(int sr, int er, int sc, int ec, int k) {
	int one = 0;
	int zro = 0;
	
	for(int i = sr; i<er; i++) {
		for(int j = sc; j<ec; j++) {
			if(v[i][j] == '1') one++;
			else zro++;		
		}
	}
	
	int totalCnt = k*k;
	if(one == totalCnt) cout << 1;
	else if(zro == totalCnt) cout << 0;
	else {
		int div = k/2;
		cout << "(";
		solve(sr, sr+div, sc, sc+div, div);
		solve(sr, sr+div, sc+div, sc+k, div);
		solve(sr+div, sr+k, sc, sc+div, div);
		solve(sr+div, sr+k, sc+div, sc+k, div);
		cout << ")";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve(0, n, 0, n, n);
	
	return 0;
}

// PM 05:43
