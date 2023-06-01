//2nd Test - 1
// start - 18:15
#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
}

int recur(int k) {
	if(k==1) return a%c;
	long long num = recur(k/2);
	num = (num * num);
	if(k%2) num = ((num%c) * (a%c));
	return num % c;
}

void solve() {
	cout << recur(b);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// fin - 18:31
