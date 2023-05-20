// acmicpc.net/problem/2577
// author : kimjihwan
// 2023-05-20 13:30

#include <iostream>
#include <string> 

using namespace std;

int arr[10];
int a, b, c;

void input() {
	cin >> a >> b >> c;
}
void solve() {
	int num = a*b*c;
	while(num) {
		arr[num%10]++;
		num/=10;
	}
	for(int i = 0; i<10; i++) cout << arr[i] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-20 PM 1:33
