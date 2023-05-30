// acmicpc.net/problem/2178
// ¹Ì·Î 
// author : kimjihwan
// 2023-05-30 PM 03:40
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
string s;

void input() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j<m; j++){
			arr[i][j] = s[j]-'0';
		}
	}
}

void solve() {
	queue<pair<int, int> > q;
	q.push({0, 0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= m) continue;
			if(arr[nx][ny] != 1) continue;
			arr[nx][ny] = arr[x][y] + 1;
			q.push({nx, ny});
		}
	}
	cout << arr[n-1][m-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
// PM 03:45
