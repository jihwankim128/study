// acmicpc.net/problem/13300
// author : kimjihwan
// 2023-05-20 PM 4:17 

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[7][2];

void input() {
	cin >> n >> k;
	for(int i = 0; i<n; i++) {
		int s, y;
		cin >> s >> y;
		arr[y][s]++;
	}
}

void solve() {
	int boy = 0, girl = 0;
	for(int i = 1; i<=6; i++) {
		if(arr[i][1]%k == 0) boy += arr[i][1]/k;
		else boy += arr[i][1]/k + 1;
		if(arr[i][0]%k == 0) girl += arr[i][0]/k; 
		else girl += arr[i][0]/k + 1;
	}
	cout << boy + girl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
	
	return 0;
}
// 2023-05-20 PM 4:21
