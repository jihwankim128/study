// acmicpc 11729
// authored by jihwankim
// study
// 23-08-22 PM 05:26
#include <bits/stdc++.h>

using namespace std;

void solve(int a, int b, int k) {
	if(k == 1) {
		cout << a << " " << b << "\n";
	}
	else {
		solve(a, 6-a-b, k-1);
		cout << a << ", " << b << "\n";
		solve(6-a-b
		, b, k-1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int k;
	cin >> k;
	cout << (1<<k)-1 << "\n";
	solve(1, 3, k);
	
	return 0;
}
// PM 05:56
