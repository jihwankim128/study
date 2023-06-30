//23-06-30 PM 06:27
//authored by jihwankim
#include <bits/stdc++.h>

using namespace std;

int n; 
int arr[10001]; 	// A_i 값이 최대 1만, counting Sort 

void input() {
	cin >> n;
	int num;
	for(int i = 0; i<n; i++) {
		cin >> num;
		arr[num]++;
	}
}

void solve() {
	//어차피 1만 까지 값이 존재하지 않으니 1만까지 반복 
	for(int i = 1; i<=10000; i++) {
		//해당 숫자가 존재한다면 출력 
		while(arr[i]) {
			cout << i << "\n";
			arr[i]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}

// PM 06:40
