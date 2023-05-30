// acmicpc.net/problem/7576
// ≈‰∏∂≈‰ 
// author : kimjihwan
// 2023-05-30 PM 04:02

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1001][1001]; 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int> > q;
int zero;

void input() {
	cin >> m >> n;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 0) zero++;
			if(arr[i][j] == 1) q.push({i, j});
		}
	}
}

void bfs() {
	int day = 1;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= m) continue;
			if(arr[nx][ny] != 0) continue;
			arr[nx][ny] = arr[x][y] + 1;
			day = max(day, arr[nx][ny]);
			zero--;
			q.push({nx, ny});
		}
	}
	
	if(zero) cout << -1;
	else cout << day - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	bfs();
	
	return 0;
}
//PM 4:17
