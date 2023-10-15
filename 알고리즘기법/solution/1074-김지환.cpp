// acmicpc 1074
// authored by jihwankim
// study
// 23-08-24 PM 06:00

#include <bits/stdc++.h>

using namespace std;

int solve(int n, int r, int c) {
	if(n==1) return 0;
	
	int div = n/2;
	int sqr = div*div;	
	
	if(r < div && c < div) return solve(div, r, c);
	if(r < div && c >= div) return sqr + solve(div, r, c-div);	
	if(r >= div && c < div) return 2 * sqr + solve(div, r-div, c);
	return 3 * sqr + solve(div, r-div, c-div);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
		
	int n, r, c;
	cin >> n >> r >> c;
	cout << solve((1<<n), r, c);
	
	return 0;
}
// PM 06:33
