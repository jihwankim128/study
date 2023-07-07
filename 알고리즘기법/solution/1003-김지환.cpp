//acm 1003
//authored by jihwankim
//23-07-03 AM 05:17
#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> n;
pair<int, int> fibo[41]; 

void input() {
	cin >> t;
	
	fibo[0] = {1, 0};
	fibo[1] = {0, 1};
	
	int num;
	
	for(int i = 0; i<t; i++){
		cin >> num;
		n.push_back(num);
	}
} 

void solve() {
	for(int i = 2; i<=40; i++) {
		fibo[i].first = fibo[i-1].first + fibo[i-2].first;
		fibo[i].second = fibo[i-1].second + fibo[i-2].second;
	}
	
	for(int i = 0; i<n.size(); i++) {
		int zero = fibo[n[i]].first;
		int one = fibo[n[i]].second;
		cout << zero << " " << one << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

/*
0 = 1 0
1 = 0 1
2 = 1 1
3 = 1 2
4 = 2 3
*/

//AM 05:25
