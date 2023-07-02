//acm 2217
//authored by jihwankim
//23-06-25 AM 12:06
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> ropes;

void input() {
	cin >> n;
	int rope; 
	for(int i = 0; i<n; i++) {
		cin >> rope;
		ropes.push_back(rope);
	}
	sort(ropes.begin(), ropes.end());
} 

void solve() {
	int maxW = 0;
	int size = ropes.size();
	for(int i = 0; i<size; i++) {
		maxW = max(maxW, ropes[i]*(size-i));
	}
	cout << maxW;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

// AM 12 : 15
