#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL)
#define h first
#define idx second
#define ll long long

using namespace std;

int n;
int arr[80001];
stack<pair<int, int> > st;
ll sum;

void input() {
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	st.push({1e9, n});
	for(int i = n-1; i>=0; i--) {
		int cnt = 0;
		while(st.top().h < arr[i]) {
			st.pop();
			cnt = (st.top().idx - i - 1);			
		}
		st.push({arr[i], i});
		//cout << i << ", " << cnt << "\n";
		sum+=cnt;
	}
	cout << sum;
}
int main() {
	input();
	solve();
	return 0;
}
