// acmicpc.net/problem/4179
// authored by kimjihwan
// 2023-05-30 PM 6:13

#include <bits/stdc++.h>

using namespace std;

int n,m;
int miro[1001][1001];
int fire[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int> > esc;
queue<pair<int, int> > fire_q;
pair<int, int> miro_q;

void input() {
	cin >> n >> m;
	string s;
	for(int i = 0; i<n; i++) {
		cin >> s;
		for(int j = 0; j<m; j++) {
			if(s[j] == '#') {
				miro[i][j] = fire[i][j] = -1;
			}
			if(s[j] == 'J') {
				fire[i][j] = -1;
				miro[i][j] = 1;
				miro_q = {i, j};
			}
			if(s[j] == 'F') {
				miro[i][j] = -1;
				fire[i][j] = 1;
				fire_q.push({i, j});
			}
			if(s[j] == '.') {
				miro[i][j] = fire[i][j] = 0;
				if(i==0 || i==(n-1)) esc.push_back({i, j});
				if(j==0 || j==(m-1)) esc.push_back({i, j});
			}
		}
	}
}

void bfs_fire() {
	while(!fire_q.empty()) {
		int x = fire_q.front().first;
		int y = fire_q.front().second; fire_q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || nx>=n) continue;
			if(ny < 0 || ny>=m) continue;
			if(fire[nx][ny] != 0) continue;
			fire[nx][ny] = fire[x][y] + 1;
			fire_q.push({nx, ny});
		}
	}
	
	/*
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cout << fire[i][j] << " ";
		}
		cout << "\n";
	}*/
}

void bfs_miro() {
	queue<pair<int, int> > q;
	q.push(miro_q);
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; q.pop();
		for(int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx < 0 || nx>=n) continue;
			if(ny < 0 || ny>=m) continue;
			if(miro[nx][ny] != 0) continue;
			if(fire[nx][ny] != 0 && miro[x][y] + 1 >= fire[nx][ny]) {
				miro[nx][ny] = -1;
				continue;
			}
			miro[nx][ny] = miro[x][y] + 1;
			q.push({nx, ny});
		}
	}
	
	/*
	cout << "\nmiro\n";
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			cout << miro[i][j] << " ";
		}
		cout << "\n";
	} */
}

void solve() {
	bfs_fire();
	bfs_miro();
	int cnt = INT_MAX;
	for(int i = 0; i<n; i++) {
	    if(miro[i][0] > 0) cnt = min(cnt, miro[i][0]);
	    if(miro[i][m-1] > 0) cnt = min(cnt, miro[i][m-1]);
	}
	for(int i = 0; i<m; i++) {
	    if(miro[0][i] > 0) cnt = min(cnt, miro[0][i]);
	    if(miro[n-1][i] > 0) cnt = min(cnt, miro[n-1][i]);
	}
	if(cnt == INT_MAX) cout << "IMPOSSIBLE";
	else cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}
//PM 6:40 + next Day 14min
