// acmicpc.net/problem/10773
// Á¦·Î 
// author : kimjihwan
// 2023-05-22 PM 04:48

#include <iostream>
#include <stack>

using namespace std;

int k;
stack<int> st;

void solve() {
	cin >> k;
	int n;
	while(k--) {
		cin >> n;
		if(!st.empty() && n == 0) st.pop();
		else st.push(n);
	}
	
	int sum = 0;
	while(!st.empty()) {
		sum += st.top();
		st.pop();
	}
	
	cout << sum;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
	return 0;
}
// 2023-05-22 PM 04:50
