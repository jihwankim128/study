// acmicpc.net/problem/1926
// ±×¸² 
// author : kimjihwan
// 2023-05-30 PM 03:23

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[505][505];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void input() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
}

int dfs(int x, int y) {
	if(x < 0 || x >= n) return 0;
	if(y < 0 || y >= m) return 0;
	if(arr[x][y] == 0) return 0;
	int cnt = 1;
	arr[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		cnt += dfs(x+dx[i], y+dy[i]);
	}
	return cnt;
}

void solve() {
	int cnt = 0;
	int max_W = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(arr[i][j]) {
				cnt++;
				max_W = max(max_W, dfs(i, j));
			}
		}
	}
	cout << cnt << "\n" << max_W;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
//PM 3:30
