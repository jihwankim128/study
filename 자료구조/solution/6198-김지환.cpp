// acmicpc.net/problem/6198 
// 옥상 정원 꾸미기 
// author : kimjihwan
// 2023-05-23 AM 10:13 

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[80005];
stack<pair<int, int> > st;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) cin >> arr[i];
}
void solve() {
	st.push({1e9+1, 0});
	long long sum = 0;
	while(n--) {
		long long cnt = 0;
		while(st.top().first < arr[n]) {
			cnt+=st.top().second + 1;
			st.pop();
		}
		sum += cnt;
		st.push({arr[n], cnt});
	}
	cout << sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-23 AN 10:44
