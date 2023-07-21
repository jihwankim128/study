//acmicpc 11286
//authored by jihwankim
//23-07-22 AM 04:45

#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<pair<int, bool>> pq;

void print() {
	if(pq.empty()) {
		cout << "0\n";
		return;
	}
	
	pair<int, bool> num = pq.top();
	pq.pop();
	
	if(!num.second) cout << -num.first << "\n";
	else cout << num.first << "\n";
}

void solve() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		int num;
		cin >> num;
		if(num < 0) {
			num = abs(num);
			pq.push({-num, true});
		}
		else if(num > 0){
			pq.push({-num, false});
		}
		else {
			print();
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
//AM 04:53
