//acmicpc 11050
//authored by jihwankim
//2023 - 06 - 15 AM 02:35

#include <iostream>

using namespace std;

int n, k; 
int fact[11] = {1,};

int C() {
	for(int i = 1; i<=10; i++) {
		fact[i] = fact[i-1] * i;
	}
	return fact[n]/(fact[n-k]*fact[k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> k;
	cout << C();
	
	return 0;
}

// AM 02:40
