#include <bits/stdc++.h>
#define fastio ios_base::sycn_with_stdio(0), cin.tie(NULL)

using namespace std;

stack<int> st;

int n;
void solve() {
	cin >> n;
	int sum = 0;
	while(n--) {
		int num;
		cin >> num;
		if(!num) {
			sum -= st.top();
			st.pop();	
		}
		else {
			sum += num;
			st.push(num);	
		}		
	}
	cout << sum;
}

int main() {
	solve();
	return 0;
}
 
