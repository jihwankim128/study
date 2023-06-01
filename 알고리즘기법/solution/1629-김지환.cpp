// acmicpc.net/problem/10026
// authored by kimjihwan
// 2023-06-01 08:50

#include <bits/stdc++.h>

using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
}

long long recur(int k) {
    if(k<=1) return a%c;
    long long num = recur(k/2);
	num*=num;
	num%=c;
    if(k%2) {
    	num*=a;
    	num%=c;
	} 
	return num;
}

void solve() {
	long long num = recur(b);
	cout << num;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
// AM 09:40
