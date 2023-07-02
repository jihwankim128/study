// 2nd Test - 2
// start - PM 6:51
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int n, m;
int arr[501][501];
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

int bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push({a, b});
	int cnt = 0;
	arr[a][b] = 0;
	
	while(!q.empty()) {
		int x = q.front().x; cnt++;
		int y = q.front().y; q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= m) continue;
			if(arr[nx][ny] == 0) continue;
			arr[nx][ny] = 0;
			q.push({nx, ny});
		}
	}
	return cnt;
}

void solve() {
	int cnt = 0;
	int max_W = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(arr[i][j] == 1) {
				cnt++;
				max_W = max(max_W, bfs(i, j));
			}
		}
	}
	cout << cnt << "\n" << max_W;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	input();
	solve();
		
	return 0;
}
// fin - PM 6:58
