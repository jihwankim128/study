//4th test
//23-07-07 PM 06:24
//authored by jihwankim

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
int dp[10001];
int maxD = 0;

void input() {
	cin >> n;
	for(int i = 1; i<=n; i++) cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	maxD = max(dp[1], dp[2]); 
}

void solve() {
	for(int i = 3; i<=n; i++) {
		dp[i] = max(dp[i-2], dp[i-3] + arr[i-1]);
		dp[i] += arr[i];
		dp[i] = max(dp[i], dp[i-1]);
		maxD = max(maxD, dp[i]);
 	}
 	cout << maxD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input(); 
	solve();
	
	return 0;
}


/*
연속 3잔 불가
n번째는 n-1을 포함 시키는가?
0 6 10 = 16
0 6 10 13 = 23 
n-3번째는 무조건 최적 상태임.
n-3 + n-2 + n 은 마실 수 있음.
n-2 는 n-3과 연속된 두 잔이므로 n-2가 최적임. 
-> n-2 + n
n-3 + n-1 + n 도 마실 수 있음.  
dp[n]이 최적이 되려면 dp[n-1]과 비교해야함.
-> 현재까지의 최적이 아니라
-> 현재의 최적이기 때문 
*/

//PM 06:39 
