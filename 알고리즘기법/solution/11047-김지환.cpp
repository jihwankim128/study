//acm 11047
//authored by jihwankim
//23-06-24 PM 11:14
#include <bits/stdc++.h>

using namespace std;

int n, m;
stack<int> coins;

void input() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		int coin;
		cin >> coin;
		coins.push(coin);
	}
} 

void solve() {
	int coin = 0;
	while(!coins.empty()) {
		coin += m/coins.top();
		m%=coins.top();
		coins.pop();
	}
	cout << coin;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// PM 11:24
