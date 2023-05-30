// acmicpc.net/problem/1926
// 그림 
// author : kimjihwan
// 2023-05-30 AM 11:39

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[505][505];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[505][505];
int maxNum = 0;

void input() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs(int x, int y, int v) {
	
}

void solve() {
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(arr[i][j] && !visited[i][j]) dfs(i, j, 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	
	return 0;
}
//continue
