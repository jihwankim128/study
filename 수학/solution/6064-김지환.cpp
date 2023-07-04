//acmicpc 6064
//authored by jihwankim
//23-07-05 AM 03:16
#include <bits/stdc++.h>

using namespace std;

int n, m, x ,y;

void input() {
	cin >> n >> m >> x >> y;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

void solve() {
	if(n == x) x = 0;
	if(m == y) y = 0;
	int nmlcm = lcm(n, m);
	for(int i = x; i<=nmlcm; i+=n) {
		if(i == 0) continue;
		if(i%m == y) {
			cout << i << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		input();
		solve();
	}	
	
	return 0;
}

//AM 03:53
