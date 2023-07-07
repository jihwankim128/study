//acmicpc 5648
//authored by jihwankim
//23-06-20 PM 01:39
#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> arr;

void input() {
	cin >> n;
	long long num;
	for(int i = 0; i<n; i++) {
		cin >> num;
		arr.push_back(num);
	}
}

long long reverseNum(long long num) {
	long long rvs = 0;
	while(num) {
		rvs *= 10;
		rvs += (num%10);
		num /= 10;
	}
	return rvs;
}

void solve() {
	long long num;
	for(int i = 0; i<n; i++) {
		num = reverseNum(arr[i]);
		arr[i] = num;
	}
	sort(arr.begin(), arr.end());
	for(int i = 0 ; i<n; i++) {
		cout << arr[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
//PM 01:49
