// acmicpc.net/problem/10026
// authored by kimjihwan
// 2023-08-21 PM 11:18

#include <bits/stdc++.h>

using namespace std;


long long solve(int a, int b, int c) {
	if(b == 1) return a % c;
	long long prod = solve(a, b/2, c);
	prod = (prod * prod) % c;
 	if(b % 2) return (prod * a) % c;
	return prod % c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c) % c;
	
	return 0;
}
// PM 11:32
