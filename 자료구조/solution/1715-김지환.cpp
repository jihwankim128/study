//acmicpc 1715
//authored by jihwankim
//23-07-22 AM 04:59

#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> pq;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int num;
		cin >> num;
		pq.push(-num);
	}	
}

void solve() {
	int cmp = 0;
	while(pq.size() > 1) {
		int card1 = -pq.top(); pq.pop();
		int card2 = -pq.top(); pq.pop();
		cmp += card1+card2;
		pq.push(-(card1+card2));
	}
	cout << cmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
		
	return 0;
}

// AM 05:13
